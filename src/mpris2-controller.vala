/*
Copyright 2010 Canonical Ltd.

Authors:
    Conor Curran <conor.curran@canonical.com>

This program is free software: you can redistribute it and/or modify it 
under the terms of the GNU General Public License version 3, as published 
by the Free Software Foundation.

This program is distributed in the hope that it will be useful, but 
WITHOUT ANY WARRANTY; without even the implied warranties of 
MERCHANTABILITY, SATISFACTORY QUALITY, or FITNESS FOR A PARTICULAR 
PURPOSE.  See the GNU General Public License for more details.

You should have received a copy of the GNU General Public License along 
with this program.  If not, see <http://www.gnu.org/licenses/>.
*/
using Dbusmenu;

[DBus (name = "org.freedesktop.DBus.Properties")]
public interface FreeDesktopProperties : Object{
  public signal void PropertiesChanged (string source, HashTable<string, Variant?> changed_properties,
                                        string[] invalid );
}

/*
 This class will entirely replace mpris-controller.vala hence why there is no
 point in trying to get encorporate both into the same object model. 
 */
public class Mpris2Controller : GLib.Object
{
  public MprisRoot mpris2_root {get; construct;}    
  public MprisPlayer player {get; construct;}
  public MprisPlaylists playlists {get; construct;}
  public FreeDesktopProperties properties_interface {get; construct;}

  public PlayerController owner {get; construct;}

  public Mpris2Controller(PlayerController ctrl)
  {
    GLib.Object(owner: ctrl);    
  }

  construct{
    try {
      this.mpris2_root = Bus.get_proxy_sync ( BusType.SESSION,
                                              this.owner.dbus_name,
                                              "/org/mpris/MediaPlayer2" );
      this.player = Bus.get_proxy_sync ( BusType.SESSION,
                                         this.owner.dbus_name,
                                         "/org/mpris/MediaPlayer2" );
      this.playlists = Bus.get_proxy_sync ( BusType.SESSION,
                                            this.owner.dbus_name,
                                            "/org/mpris/MediaPlayer2" );
      
      this.properties_interface = Bus.get_proxy_sync ( BusType.SESSION,
                                                       "org.freedesktop.Properties.PropertiesChanged",
                                                       "/org/mpris/MediaPlayer2" );
      this.properties_interface.PropertiesChanged.connect ( property_changed_cb );
    }
    catch (IOError e) {
      error("Problems connecting to the session bus - %s", e.message);
    }
  }

  public void property_changed_cb ( string interface_source,
                                    HashTable<string, Variant?> changed_properties,
                                    string[] invalid )
  {
    debug("properties-changed for interface %s and owner %s", interface_source, this.owner.dbus_name);
    if ( changed_properties == null ||
        interface_source.has_prefix ( Mpris2Watcher.MPRIS_PREFIX ) == false ){
      warning("Property-changed hash is null or this is an interface that doesn't concerns us");
      return;
    }
    Variant? play_v = changed_properties.lookup("PlaybackStatus");
    if(play_v != null){
      // Race condition sometimes appears with the playback status 
      // 200ms timeout ensures we have the correct playback status at all times.
      string state = this.player.PlaybackStatus;
      //debug("in the property update and the playback status = %s and update = %s", state, (string)play_v);
      Timeout.add ( 200, ensure_correct_playback_status );
      TransportMenuitem.state p = (TransportMenuitem.state)this.determine_play_state(state);
      (this.owner.custom_items[PlayerController.widget_order.TRANSPORT] as TransportMenuitem).change_play_state(p);
    }
    Variant? meta_v = changed_properties.lookup("Metadata");
    if(meta_v != null){
      GLib.HashTable<string, Variant?> changed_updates = clean_metadata();
      PlayerItem metadata = this.owner.custom_items[PlayerController.widget_order.METADATA];
      metadata.reset ( MetadataMenuitem.attributes_format());
      metadata.update ( changed_updates, 
                        MetadataMenuitem.attributes_format());
      metadata.property_set_bool ( MENUITEM_PROP_VISIBLE,
                                   metadata.populated(MetadataMenuitem.attributes_format()));
    }
    Variant? playlist_v = changed_properties.lookup("ActivePlaylist");
    if ( playlist_v != null ){
      this.fetch_active_playlist();
    }
  }

  public bool playlist_support()
  {
    // awaiting spec updates
    // return this.mpris2_root.HasPlaylists;
    return true;  
  }
  
  private bool ensure_correct_playback_status(){
    debug("TEST playback status = %s", this.player.PlaybackStatus);
    TransportMenuitem.state p = (TransportMenuitem.state)this.determine_play_state(this.player.PlaybackStatus);
    (this.owner.custom_items[PlayerController.widget_order.TRANSPORT] as TransportMenuitem).change_play_state(p);
    return false;
  }
  
  private GLib.HashTable<string, Variant?>? clean_metadata()
  { 
    GLib.HashTable<string, Variant?> changed_updates = this.player.Metadata; 
    Variant? artist_v = this.player.Metadata.lookup("xesam:artist");
    if(artist_v != null){
      string[] artists = (string[])this.player.Metadata.lookup("xesam:artist");
      string display_artists = string.joinv(", ", artists);
      changed_updates.replace("xesam:artist", display_artists);
      debug("artist : %s", (string)changed_updates.lookup("xesam:artist"));
    }
    Variant? length_v = this.player.Metadata.lookup("mpris:length");
    if(length_v != null){
      int64 duration = this.player.Metadata.lookup("mpris:length").get_int64();
      changed_updates.replace("mpris:length", duration/1000000); 
    }
    return changed_updates;
  }
  
  private TransportMenuitem.state determine_play_state(string? status){ 
    if(status != null && status == "Playing"){
      return TransportMenuitem.state.PLAYING;
    }
    return TransportMenuitem.state.PAUSED;
  }

  public void initial_update()
  {
    TransportMenuitem.state update;
    if(this.player.PlaybackStatus == null){
      update = TransportMenuitem.state.PAUSED;
    }

    update = determine_play_state(null);
   
    (this.owner.custom_items[PlayerController.widget_order.TRANSPORT] as TransportMenuitem).change_play_state(TransportMenuitem.state.PAUSED);
    GLib.HashTable<string, Value?>? cleaned_metadata = this.clean_metadata();
    this.owner.custom_items[PlayerController.widget_order.METADATA].update(cleaned_metadata,
                                                                            MetadataMenuitem.attributes_format());
    this.fetch_playlists();
  }

  public void transport_update(TransportMenuitem.action command)
  {
    debug("transport_event input = %i", (int)command);
    if(command == TransportMenuitem.action.PLAY_PAUSE){
      this.player.PlayPause.begin();              
    }
    else if(command == TransportMenuitem.action.PREVIOUS){
      this.player.Previous.begin();
    }
    else if(command == TransportMenuitem.action.NEXT){
      this.player.Next.begin();
    }
  }

  public void fetch_playlists()
  {
    if (this.playlists == null){
      warning("Playlists object is null");
      return;
    }
    PlaylistDetails[] current_playlists =  this.playlists.GetPlaylists(0,
                                                                       10,
                                                                       "Alphabetical",
                                                                       false);
    if( current_playlists != null ){
      debug( "Size of the playlist array = %i", current_playlists.length );
      PlaylistsMenuitem playlists_item = this.owner.custom_items[PlayerController.widget_order.PLAYLISTS] as PlaylistsMenuitem;
      playlists_item.update(current_playlists);
      /*foreach(PlaylistDetails detail in current_playlists){ 
        debug(" \n \n ");
        debug( "Playlist Name = %s", detail.name);
        debug( "Playlist path = %s", detail.path);
        debug( "Playlist icon path = %s", detail.icon_path);
        debug(" \n \n ");
      }*/
    }
  }

  public void fetch_active_playlist()
  {
    if (this.playlists == null && this.playlists.ActivePlaylist.valid == true){
      warning("Playlists object is null or we don't have an active playlist");
      return;
    }
    PlaylistsMenuitem playlists_item = this.owner.custom_items[PlayerController.widget_order.PLAYLISTS] as PlaylistsMenuitem;
    playlists_item.update_active_playlist ( this.playlists.ActivePlaylist.details );
    /*debug(" \n \n ");
    debug( "Active Playlist Name = %s", active_details.name);
    debug( "Active Playlist path = %s", active_details.path);
    debug( "Active Playlist icon path = %s", active_details.icon_path);
    debug(" \n \n ");
    */
  }


  public bool connected()
  {
    return (this.player != null && this.mpris2_root != null);
  }
  
  public void expose()
  {
    if(this.connected() == true){
      this.mpris2_root.Raise.begin();
    }
  }

  public void activate_playlist (ObjectPath path)
  {
    if(this.playlists == null){
      warning("playlists mpris instance is null !");
      return;       
    }
    try{
      this.playlists.ActivatePlaylist.begin(path);
    }
    catch(IOError e){
      debug("Could not activate playlist %s because %s", (string)path, e.message);     
    }
  } 
}