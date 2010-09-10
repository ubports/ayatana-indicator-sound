/* music-player-bridge.c generated by valac 0.9.8, the Vala compiler
 * generated from music-player-bridge.vala, do not modify */

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

#include <glib.h>
#include <glib-object.h>
#include <libindicate/./indicator-messages.h>
#include <libindicate/./indicator.h>
#include <libindicate/./interests.h>
#include <libindicate/./listener.h>
#include <libindicate/./server.h>
#include <libdbusmenu-glib/client.h>
#include <libdbusmenu-glib/menuitem-proxy.h>
#include <libdbusmenu-glib/menuitem.h>
#include <libdbusmenu-glib/server.h>
#include <gee.h>
#include <stdlib.h>
#include <string.h>
#include <gio/gdesktopappinfo.h>
#include <gio/gio.h>


#define TYPE_MUSIC_PLAYER_BRIDGE (music_player_bridge_get_type ())
#define MUSIC_PLAYER_BRIDGE(obj) (G_TYPE_CHECK_INSTANCE_CAST ((obj), TYPE_MUSIC_PLAYER_BRIDGE, MusicPlayerBridge))
#define MUSIC_PLAYER_BRIDGE_CLASS(klass) (G_TYPE_CHECK_CLASS_CAST ((klass), TYPE_MUSIC_PLAYER_BRIDGE, MusicPlayerBridgeClass))
#define IS_MUSIC_PLAYER_BRIDGE(obj) (G_TYPE_CHECK_INSTANCE_TYPE ((obj), TYPE_MUSIC_PLAYER_BRIDGE))
#define IS_MUSIC_PLAYER_BRIDGE_CLASS(klass) (G_TYPE_CHECK_CLASS_TYPE ((klass), TYPE_MUSIC_PLAYER_BRIDGE))
#define MUSIC_PLAYER_BRIDGE_GET_CLASS(obj) (G_TYPE_INSTANCE_GET_CLASS ((obj), TYPE_MUSIC_PLAYER_BRIDGE, MusicPlayerBridgeClass))

typedef struct _MusicPlayerBridge MusicPlayerBridge;
typedef struct _MusicPlayerBridgeClass MusicPlayerBridgeClass;
typedef struct _MusicPlayerBridgePrivate MusicPlayerBridgePrivate;

#define TYPE_PLAYER_CONTROLLER (player_controller_get_type ())
#define PLAYER_CONTROLLER(obj) (G_TYPE_CHECK_INSTANCE_CAST ((obj), TYPE_PLAYER_CONTROLLER, PlayerController))
#define PLAYER_CONTROLLER_CLASS(klass) (G_TYPE_CHECK_CLASS_CAST ((klass), TYPE_PLAYER_CONTROLLER, PlayerControllerClass))
#define IS_PLAYER_CONTROLLER(obj) (G_TYPE_CHECK_INSTANCE_TYPE ((obj), TYPE_PLAYER_CONTROLLER))
#define IS_PLAYER_CONTROLLER_CLASS(klass) (G_TYPE_CHECK_CLASS_TYPE ((klass), TYPE_PLAYER_CONTROLLER))
#define PLAYER_CONTROLLER_GET_CLASS(obj) (G_TYPE_INSTANCE_GET_CLASS ((obj), TYPE_PLAYER_CONTROLLER, PlayerControllerClass))

typedef struct _PlayerController PlayerController;
typedef struct _PlayerControllerClass PlayerControllerClass;

#define TYPE_FAMILIAR_PLAYERS_DB (familiar_players_db_get_type ())
#define FAMILIAR_PLAYERS_DB(obj) (G_TYPE_CHECK_INSTANCE_CAST ((obj), TYPE_FAMILIAR_PLAYERS_DB, FamiliarPlayersDB))
#define FAMILIAR_PLAYERS_DB_CLASS(klass) (G_TYPE_CHECK_CLASS_CAST ((klass), TYPE_FAMILIAR_PLAYERS_DB, FamiliarPlayersDBClass))
#define IS_FAMILIAR_PLAYERS_DB(obj) (G_TYPE_CHECK_INSTANCE_TYPE ((obj), TYPE_FAMILIAR_PLAYERS_DB))
#define IS_FAMILIAR_PLAYERS_DB_CLASS(klass) (G_TYPE_CHECK_CLASS_TYPE ((klass), TYPE_FAMILIAR_PLAYERS_DB))
#define FAMILIAR_PLAYERS_DB_GET_CLASS(obj) (G_TYPE_INSTANCE_GET_CLASS ((obj), TYPE_FAMILIAR_PLAYERS_DB, FamiliarPlayersDBClass))

typedef struct _FamiliarPlayersDB FamiliarPlayersDB;
typedef struct _FamiliarPlayersDBClass FamiliarPlayersDBClass;
#define _g_object_unref0(var) ((var == NULL) ? NULL : (var = (g_object_unref (var), NULL)))
#define _g_free0(var) (var = (g_free (var), NULL))

#define PLAYER_CONTROLLER_TYPE_STATE (player_controller_state_get_type ())

struct _MusicPlayerBridge {
	GObject parent_instance;
	MusicPlayerBridgePrivate * priv;
};

struct _MusicPlayerBridgeClass {
	GObjectClass parent_class;
};

struct _MusicPlayerBridgePrivate {
	IndicateListener* listener;
	DbusmenuMenuitem* root_menu;
	GeeHashMap* registered_clients;
	FamiliarPlayersDB* playersDB;
};

typedef enum  {
	PLAYER_CONTROLLER_STATE_OFFLINE,
	PLAYER_CONTROLLER_STATE_INSTANTIATING,
	PLAYER_CONTROLLER_STATE_READY,
	PLAYER_CONTROLLER_STATE_CONNECTED,
	PLAYER_CONTROLLER_STATE_DISCONNECTED
} PlayerControllerstate;


static gpointer music_player_bridge_parent_class = NULL;

GType music_player_bridge_get_type (void) G_GNUC_CONST;
GType player_controller_get_type (void) G_GNUC_CONST;
GType familiar_players_db_get_type (void) G_GNUC_CONST;
#define MUSIC_PLAYER_BRIDGE_GET_PRIVATE(o) (G_TYPE_INSTANCE_GET_PRIVATE ((o), TYPE_MUSIC_PLAYER_BRIDGE, MusicPlayerBridgePrivate))
enum  {
	MUSIC_PLAYER_BRIDGE_DUMMY_PROPERTY
};
MusicPlayerBridge* music_player_bridge_new (void);
MusicPlayerBridge* music_player_bridge_construct (GType object_type);
FamiliarPlayersDB* familiar_players_db_new (void);
FamiliarPlayersDB* familiar_players_db_construct (GType object_type);
void music_player_bridge_on_indicator_added (MusicPlayerBridge* self, IndicateListenerServer* object, IndicateListenerIndicator* p0);
static void _music_player_bridge_on_indicator_added_indicate_listener_indicator_added (IndicateListener* _sender, IndicateListenerServer* object, IndicateListenerIndicator* p0, gpointer self);
void music_player_bridge_on_indicator_removed (MusicPlayerBridge* self, IndicateListenerServer* object, IndicateListenerIndicator* p0);
static void _music_player_bridge_on_indicator_removed_indicate_listener_indicator_removed (IndicateListener* _sender, IndicateListenerServer* object, IndicateListenerIndicator* p0, gpointer self);
void music_player_bridge_on_indicator_modified (MusicPlayerBridge* self, IndicateListenerServer* object, IndicateListenerIndicator* p0, const char* s);
static void _music_player_bridge_on_indicator_modified_indicate_listener_indicator_modified (IndicateListener* _sender, IndicateListenerServer* object, IndicateListenerIndicator* p0, const char* p1, gpointer self);
void music_player_bridge_on_server_added (MusicPlayerBridge* self, IndicateListenerServer* object, const char* type);
static void _music_player_bridge_on_server_added_indicate_listener_server_added (IndicateListener* _sender, IndicateListenerServer* object, const char* p0, gpointer self);
void music_player_bridge_on_server_removed (MusicPlayerBridge* self, IndicateListenerServer* object, const char* type);
static void _music_player_bridge_on_server_removed_indicate_listener_server_removed (IndicateListener* _sender, IndicateListenerServer* object, const char* p0, gpointer self);
void music_player_bridge_on_server_count_changed (MusicPlayerBridge* self, IndicateListenerServer* object, guint i);
static void _music_player_bridge_on_server_count_changed_indicate_listener_server_count_changed (IndicateListener* _sender, IndicateListenerServer* object, guint p0, gpointer self);
static void music_player_bridge_try_to_add_inactive_familiar_clients (MusicPlayerBridge* self);
GeeSet* familiar_players_db_records (FamiliarPlayersDB* self);
static char* music_player_bridge_truncate_player_name (const char* app_info_name);
static gint music_player_bridge_calculate_menu_position (MusicPlayerBridge* self);
GType player_controller_state_get_type (void) G_GNUC_CONST;
PlayerController* player_controller_new (DbusmenuMenuitem* root, const char* client_name, gint offset, PlayerControllerstate initial_state);
PlayerController* player_controller_construct (GType object_type, DbusmenuMenuitem* root, const char* client_name, gint offset, PlayerControllerstate initial_state);
void player_controller_set_app_info (PlayerController* self, GAppInfo* value);
GAppInfo* player_controller_get_app_info (PlayerController* self);
#define PLAYER_CONTROLLER_WIDGET_QUANTITY 4
static gboolean music_player_bridge_server_is_not_of_interest (MusicPlayerBridge* self, const char* type);
void player_controller_update_state (PlayerController* self, PlayerControllerstate new_state);
void player_controller_activate (PlayerController* self);
static void music_player_bridge_desktop_info_callback (MusicPlayerBridge* self, IndicateListenerServer* server, char* path, void* data);
void player_controller_hibernate (PlayerController* self);
gboolean familiar_players_db_already_familiar (FamiliarPlayersDB* self, const char* desktop);
void familiar_players_db_insert (FamiliarPlayersDB* self, const char* desktop);
GAppInfo* music_player_bridge_create_app_info (const char* path);
void music_player_bridge_set_root_menu_item (MusicPlayerBridge* self, DbusmenuMenuitem* menu);
static void music_player_bridge_finalize (GObject* obj);
static void _vala_array_destroy (gpointer array, gint array_length, GDestroyNotify destroy_func);
static void _vala_array_free (gpointer array, gint array_length, GDestroyNotify destroy_func);
static gint _vala_array_length (gpointer array);



static void _music_player_bridge_on_indicator_added_indicate_listener_indicator_added (IndicateListener* _sender, IndicateListenerServer* object, IndicateListenerIndicator* p0, gpointer self) {
	music_player_bridge_on_indicator_added (self, object, p0);
}


static void _music_player_bridge_on_indicator_removed_indicate_listener_indicator_removed (IndicateListener* _sender, IndicateListenerServer* object, IndicateListenerIndicator* p0, gpointer self) {
	music_player_bridge_on_indicator_removed (self, object, p0);
}


static void _music_player_bridge_on_indicator_modified_indicate_listener_indicator_modified (IndicateListener* _sender, IndicateListenerServer* object, IndicateListenerIndicator* p0, const char* p1, gpointer self) {
	music_player_bridge_on_indicator_modified (self, object, p0, p1);
}


static void _music_player_bridge_on_server_added_indicate_listener_server_added (IndicateListener* _sender, IndicateListenerServer* object, const char* p0, gpointer self) {
	music_player_bridge_on_server_added (self, object, p0);
}


static void _music_player_bridge_on_server_removed_indicate_listener_server_removed (IndicateListener* _sender, IndicateListenerServer* object, const char* p0, gpointer self) {
	music_player_bridge_on_server_removed (self, object, p0);
}


static void _music_player_bridge_on_server_count_changed_indicate_listener_server_count_changed (IndicateListener* _sender, IndicateListenerServer* object, guint p0, gpointer self) {
	music_player_bridge_on_server_count_changed (self, object, p0);
}


MusicPlayerBridge* music_player_bridge_construct (GType object_type) {
	MusicPlayerBridge * self;
	FamiliarPlayersDB* _tmp0_;
	GeeHashMap* _tmp1_;
	IndicateListener* _tmp2_;
	self = (MusicPlayerBridge*) g_object_new (object_type, NULL);
	self->priv->playersDB = (_tmp0_ = familiar_players_db_new (), _g_object_unref0 (self->priv->playersDB), _tmp0_);
	self->priv->registered_clients = (_tmp1_ = gee_hash_map_new (G_TYPE_STRING, (GBoxedCopyFunc) g_strdup, g_free, TYPE_PLAYER_CONTROLLER, (GBoxedCopyFunc) g_object_ref, g_object_unref, NULL, NULL, NULL), _g_object_unref0 (self->priv->registered_clients), _tmp1_);
	self->priv->listener = (_tmp2_ = indicate_listener_ref_default (), _g_object_unref0 (self->priv->listener), _tmp2_);
	g_signal_connect_object (self->priv->listener, "indicator-added", (GCallback) _music_player_bridge_on_indicator_added_indicate_listener_indicator_added, self, 0);
	g_signal_connect_object (self->priv->listener, "indicator-removed", (GCallback) _music_player_bridge_on_indicator_removed_indicate_listener_indicator_removed, self, 0);
	g_signal_connect_object (self->priv->listener, "indicator-modified", (GCallback) _music_player_bridge_on_indicator_modified_indicate_listener_indicator_modified, self, 0);
	g_signal_connect_object (self->priv->listener, "server-added", (GCallback) _music_player_bridge_on_server_added_indicate_listener_server_added, self, 0);
	g_signal_connect_object (self->priv->listener, "server-removed", (GCallback) _music_player_bridge_on_server_removed_indicate_listener_server_removed, self, 0);
	g_signal_connect_object (self->priv->listener, "server-count-changed", (GCallback) _music_player_bridge_on_server_count_changed_indicate_listener_server_count_changed, self, 0);
	return self;
}


MusicPlayerBridge* music_player_bridge_new (void) {
	return music_player_bridge_construct (TYPE_MUSIC_PLAYER_BRIDGE);
}


static gpointer _g_object_ref0 (gpointer self) {
	return self ? g_object_ref (self) : NULL;
}


static void music_player_bridge_try_to_add_inactive_familiar_clients (MusicPlayerBridge* self) {
	g_return_if_fail (self != NULL);
	{
		GeeSet* _tmp0_;
		GeeIterator* _tmp1_;
		GeeIterator* _app_it;
		_app_it = (_tmp1_ = gee_iterable_iterator ((GeeIterable*) (_tmp0_ = familiar_players_db_records (self->priv->playersDB))), _g_object_unref0 (_tmp0_), _tmp1_);
		while (TRUE) {
			char* app;
			GDesktopAppInfo* info;
			GDesktopAppInfo* _tmp2_;
			GAppInfo* app_info;
			char* _tmp3_;
			PlayerController* _tmp4_;
			PlayerController* ctrl;
			char* _tmp5_;
			if (!gee_iterator_next (_app_it)) {
				break;
			}
			app = (char*) gee_iterator_get (_app_it);
			if (app == NULL) {
				g_warning ("music-player-bridge.vala:49: App string in keyfile is null therefore m" \
"oving on to next player");
				_g_free0 (app);
				continue;
			}
			g_debug ("music-player-bridge.vala:53: attempting to make an app info from %s", app);
			info = g_desktop_app_info_new_from_filename (app);
			if (info == NULL) {
				g_warning ("music-player-bridge.vala:57: Could not create a desktopappinfo instanc" \
"e from app: %s", app);
				_g_object_unref0 (info);
				_g_free0 (app);
				continue;
			}
			app_info = _g_object_ref0 ((_tmp2_ = info, G_IS_APP_INFO (_tmp2_) ? ((GAppInfo*) _tmp2_) : NULL));
			ctrl = (_tmp4_ = player_controller_new (self->priv->root_menu, _tmp3_ = music_player_bridge_truncate_player_name (g_app_info_get_name (app_info)), music_player_bridge_calculate_menu_position (self), PLAYER_CONTROLLER_STATE_OFFLINE), _g_free0 (_tmp3_), _tmp4_);
			player_controller_set_app_info (ctrl, app_info);
			if (player_controller_get_app_info (ctrl) == NULL) {
				g_warning ("music-player-bridge.vala:69: for some reason the app info is null");
			}
			gee_abstract_map_set ((GeeAbstractMap*) self->priv->registered_clients, _tmp5_ = music_player_bridge_truncate_player_name (g_app_info_get_name (app_info)), ctrl);
			_g_free0 (_tmp5_);
			_g_object_unref0 (ctrl);
			_g_object_unref0 (app_info);
			_g_object_unref0 (info);
			_g_free0 (app);
		}
		_g_object_unref0 (_app_it);
	}
}


static char* string_strip (const char* self) {
	char* result = NULL;
	char* _result_;
	g_return_val_if_fail (self != NULL, NULL);
	_result_ = g_strdup (self);
	g_strstrip (_result_);
	result = _result_;
	return result;
}


static char* music_player_bridge_truncate_player_name (const char* app_info_name) {
	char* result = NULL;
	char* _tmp0_;
	char* _tmp1_;
	char* _result_;
	gint tokens_length1;
	gint _tokens_size_;
	char** _tmp3_;
	char** _tmp2_;
	char** tokens;
	g_return_val_if_fail (app_info_name != NULL, NULL);
	_result_ = (_tmp1_ = string_strip (_tmp0_ = g_utf8_strdown (app_info_name, -1)), _g_free0 (_tmp0_), _tmp1_);
	tokens = (_tmp3_ = _tmp2_ = g_strsplit (_result_, " ", 0), tokens_length1 = _vala_array_length (_tmp2_), _tokens_size_ = tokens_length1, _tmp3_);
	if (tokens_length1 > 1) {
		char* _tmp4_;
		_result_ = (_tmp4_ = g_strdup (tokens[0]), _g_free0 (_result_), _tmp4_);
	}
	g_debug ("music-player-bridge.vala:84: truncate player name %s", _result_);
	result = _result_;
	tokens = (_vala_array_free (tokens, tokens_length1, (GDestroyNotify) g_free), NULL);
	return result;
}


static gint music_player_bridge_calculate_menu_position (MusicPlayerBridge* self) {
	gint result = 0;
	g_return_val_if_fail (self != NULL, 0);
	if (gee_map_get_size ((GeeMap*) self->priv->registered_clients) == 0) {
		result = 2;
		return result;
	} else {
		result = 2 + (gee_map_get_size ((GeeMap*) self->priv->registered_clients) * PLAYER_CONTROLLER_WIDGET_QUANTITY);
		return result;
	}
}


void music_player_bridge_on_server_added (MusicPlayerBridge* self, IndicateListenerServer* object, const char* type) {
	char** _tmp0_;
	char** _tmp1_;
	gint _tmp1__length1;
	char* _tmp2_;
	char* client_name;
	gboolean _tmp3_ = FALSE;
	g_return_if_fail (self != NULL);
	g_return_if_fail (type != NULL);
	g_debug ("music-player-bridge.vala:100: MusicPlayerBridge -> on_server_added wit" \
"h value %s", type);
	if (music_player_bridge_server_is_not_of_interest (self, type)) {
		return;
	}
	client_name = (_tmp2_ = g_strdup ((_tmp1_ = _tmp0_ = g_strsplit (type, ".", 0), _tmp1__length1 = _vala_array_length (_tmp0_), _tmp1_)[1]), _tmp1_ = (_vala_array_free (_tmp1_, _tmp1__length1, (GDestroyNotify) g_free), NULL), _tmp2_);
	if (self->priv->root_menu != NULL) {
		_tmp3_ = client_name != NULL;
	} else {
		_tmp3_ = FALSE;
	}
	if (_tmp3_) {
		GeeSet* _tmp4_;
		gboolean _tmp5_;
		PlayerController* _tmp8_;
		gboolean _tmp9_;
		if ((_tmp5_ = gee_collection_contains ((GeeCollection*) (_tmp4_ = gee_map_get_keys ((GeeMap*) self->priv->registered_clients)), client_name), _g_object_unref0 (_tmp4_), _tmp5_)) {
			PlayerController* _tmp6_;
			PlayerController* _tmp7_;
			g_debug ("music-player-bridge.vala:106: It figured out that it already has an in" \
"stance for this player already");
			player_controller_update_state (_tmp6_ = (PlayerController*) gee_abstract_map_get ((GeeAbstractMap*) self->priv->registered_clients, client_name), PLAYER_CONTROLLER_STATE_READY);
			_g_object_unref0 (_tmp6_);
			player_controller_activate (_tmp7_ = (PlayerController*) gee_abstract_map_get ((GeeAbstractMap*) self->priv->registered_clients, client_name));
			_g_object_unref0 (_tmp7_);
		} else {
			PlayerController* ctrl;
			ctrl = player_controller_new (self->priv->root_menu, client_name, music_player_bridge_calculate_menu_position (self), PLAYER_CONTROLLER_STATE_READY);
			gee_abstract_map_set ((GeeAbstractMap*) self->priv->registered_clients, client_name, ctrl);
			g_debug ("music-player-bridge.vala:117: New Client of name %s has successfully r" \
"egistered with us", client_name);
			_g_object_unref0 (ctrl);
		}
		if ((_tmp9_ = player_controller_get_app_info (_tmp8_ = (PlayerController*) gee_abstract_map_get ((GeeAbstractMap*) self->priv->registered_clients, client_name)) == NULL, _g_object_unref0 (_tmp8_), _tmp9_)) {
			indicate_listener_get_server_property_cb cb;
			cb = (indicate_listener_get_server_property_cb) music_player_bridge_desktop_info_callback;
			indicate_listener_server_get_desktop (self->priv->listener, object, cb, self);
		}
	}
	_g_free0 (client_name);
}


void music_player_bridge_on_server_removed (MusicPlayerBridge* self, IndicateListenerServer* object, const char* type) {
	char** _tmp0_;
	char** _tmp1_;
	gint _tmp1__length1;
	char* _tmp2_;
	char* client_name;
	gboolean _tmp3_ = FALSE;
	g_return_if_fail (self != NULL);
	g_return_if_fail (type != NULL);
	g_debug ("music-player-bridge.vala:129: MusicPlayerBridge -> on_server_removed w" \
"ith value %s", type);
	if (music_player_bridge_server_is_not_of_interest (self, type)) {
		return;
	}
	client_name = (_tmp2_ = g_strdup ((_tmp1_ = _tmp0_ = g_strsplit (type, ".", 0), _tmp1__length1 = _vala_array_length (_tmp0_), _tmp1_)[1]), _tmp1_ = (_vala_array_free (_tmp1_, _tmp1__length1, (GDestroyNotify) g_free), NULL), _tmp2_);
	if (self->priv->root_menu != NULL) {
		_tmp3_ = client_name != NULL;
	} else {
		_tmp3_ = FALSE;
	}
	if (_tmp3_) {
		PlayerController* _tmp4_;
		player_controller_hibernate (_tmp4_ = (PlayerController*) gee_abstract_map_get ((GeeAbstractMap*) self->priv->registered_clients, client_name));
		_g_object_unref0 (_tmp4_);
		g_debug ("music-player-bridge.vala:134: Successively offlined client %s", client_name);
	}
	_g_free0 (client_name);
}


static gboolean string_contains (const char* self, const char* needle) {
	gboolean result = FALSE;
	g_return_val_if_fail (self != NULL, FALSE);
	g_return_val_if_fail (needle != NULL, FALSE);
	result = strstr (self, needle) != NULL;
	return result;
}


static gboolean music_player_bridge_server_is_not_of_interest (MusicPlayerBridge* self, const char* type) {
	gboolean result = FALSE;
	g_return_val_if_fail (self != NULL, FALSE);
	g_return_val_if_fail (type != NULL, FALSE);
	if (type == NULL) {
		result = TRUE;
		return result;
	}
	if (string_contains (type, "music") == FALSE) {
		g_debug ("music-player-bridge.vala:141: server is of no interest,  it is not an " \
"music server");
		result = TRUE;
		return result;
	}
	result = FALSE;
	return result;
}


static void music_player_bridge_desktop_info_callback (MusicPlayerBridge* self, IndicateListenerServer* server, char* path, void* data) {
	void* _tmp0_;
	MusicPlayerBridge* bridge;
	gboolean _tmp1_ = FALSE;
	g_return_if_fail (self != NULL);
	g_return_if_fail (path != NULL);
	bridge = _g_object_ref0 ((_tmp0_ = data, IS_MUSIC_PLAYER_BRIDGE (_tmp0_) ? ((MusicPlayerBridge*) _tmp0_) : NULL));
	if (string_contains (path, "/")) {
		_tmp1_ = familiar_players_db_already_familiar (bridge->priv->playersDB, path) == FALSE;
	} else {
		_tmp1_ = FALSE;
	}
	if (_tmp1_) {
		GAppInfo* app_info;
		g_debug ("music-player-bridge.vala:152: About to store desktop file path: %s", path);
		familiar_players_db_insert (bridge->priv->playersDB, path);
		app_info = music_player_bridge_create_app_info (path);
		if (app_info != NULL) {
			char* _tmp2_;
			char* _tmp3_;
			PlayerController* _tmp4_;
			PlayerController* ctrl;
			ctrl = (_tmp4_ = (PlayerController*) gee_abstract_map_get ((GeeAbstractMap*) bridge->priv->registered_clients, _tmp3_ = string_strip (_tmp2_ = g_utf8_strdown (g_app_info_get_name (app_info), -1))), _g_free0 (_tmp3_), _g_free0 (_tmp2_), _tmp4_);
			g_object_set ((GObject*) ctrl, "app_info", app_info, NULL);
			g_debug ("music-player-bridge.vala:158: successfully created appinfo from path a" \
"nd set it on the respective instance");
			_g_object_unref0 (ctrl);
		}
		_g_object_unref0 (app_info);
	} else {
		g_debug ("music-player-bridge.vala:162: Ignoring desktop file path because its e" \
"ither invalid of the db cache file has it already: %s", path);
	}
	_g_object_unref0 (bridge);
	_g_free0 (path);
}


void music_player_bridge_set_root_menu_item (MusicPlayerBridge* self, DbusmenuMenuitem* menu) {
	DbusmenuMenuitem* _tmp0_;
	g_return_if_fail (self != NULL);
	g_return_if_fail (menu != NULL);
	self->priv->root_menu = (_tmp0_ = _g_object_ref0 (menu), _g_object_unref0 (self->priv->root_menu), _tmp0_);
	music_player_bridge_try_to_add_inactive_familiar_clients (self);
}


void music_player_bridge_on_server_count_changed (MusicPlayerBridge* self, IndicateListenerServer* object, guint i) {
	g_return_if_fail (self != NULL);
	g_debug ("music-player-bridge.vala:174: MusicPlayerBridge-> on_server_count_chan" \
"ged with value %u", i);
}


void music_player_bridge_on_indicator_added (MusicPlayerBridge* self, IndicateListenerServer* object, IndicateListenerIndicator* p0) {
	g_return_if_fail (self != NULL);
	g_debug ("music-player-bridge.vala:178: MusicPlayerBridge-> on_indicator_added");
}


void music_player_bridge_on_indicator_removed (MusicPlayerBridge* self, IndicateListenerServer* object, IndicateListenerIndicator* p0) {
	g_return_if_fail (self != NULL);
	g_debug ("music-player-bridge.vala:183: MusicPlayerBridge -> on_indicator_remove" \
"d");
}


void music_player_bridge_on_indicator_modified (MusicPlayerBridge* self, IndicateListenerServer* object, IndicateListenerIndicator* p0, const char* s) {
	g_return_if_fail (self != NULL);
	g_return_if_fail (s != NULL);
	g_debug ("music-player-bridge.vala:188: MusicPlayerBridge -> indicator_modified " \
"with vale %s", s);
}


GAppInfo* music_player_bridge_create_app_info (const char* path) {
	GAppInfo* result = NULL;
	GDesktopAppInfo* info;
	GDesktopAppInfo* _tmp0_;
	GAppInfo* app_info;
	g_return_val_if_fail (path != NULL, NULL);
	info = g_desktop_app_info_new_from_filename (path);
	if (path == NULL) {
		g_warning ("music-player-bridge.vala:195: Could not create a desktopappinfo instan" \
"ce from app: %s", path);
		result = NULL;
		_g_object_unref0 (info);
		return result;
	}
	app_info = _g_object_ref0 ((_tmp0_ = info, G_IS_APP_INFO (_tmp0_) ? ((GAppInfo*) _tmp0_) : NULL));
	result = app_info;
	_g_object_unref0 (info);
	return result;
}


static void music_player_bridge_class_init (MusicPlayerBridgeClass * klass) {
	music_player_bridge_parent_class = g_type_class_peek_parent (klass);
	g_type_class_add_private (klass, sizeof (MusicPlayerBridgePrivate));
	G_OBJECT_CLASS (klass)->finalize = music_player_bridge_finalize;
}


static void music_player_bridge_instance_init (MusicPlayerBridge * self) {
	self->priv = MUSIC_PLAYER_BRIDGE_GET_PRIVATE (self);
}


static void music_player_bridge_finalize (GObject* obj) {
	MusicPlayerBridge * self;
	self = MUSIC_PLAYER_BRIDGE (obj);
	_g_object_unref0 (self->priv->listener);
	_g_object_unref0 (self->priv->root_menu);
	_g_object_unref0 (self->priv->registered_clients);
	_g_object_unref0 (self->priv->playersDB);
	G_OBJECT_CLASS (music_player_bridge_parent_class)->finalize (obj);
}


GType music_player_bridge_get_type (void) {
	static volatile gsize music_player_bridge_type_id__volatile = 0;
	if (g_once_init_enter (&music_player_bridge_type_id__volatile)) {
		static const GTypeInfo g_define_type_info = { sizeof (MusicPlayerBridgeClass), (GBaseInitFunc) NULL, (GBaseFinalizeFunc) NULL, (GClassInitFunc) music_player_bridge_class_init, (GClassFinalizeFunc) NULL, NULL, sizeof (MusicPlayerBridge), 0, (GInstanceInitFunc) music_player_bridge_instance_init, NULL };
		GType music_player_bridge_type_id;
		music_player_bridge_type_id = g_type_register_static (G_TYPE_OBJECT, "MusicPlayerBridge", &g_define_type_info, 0);
		g_once_init_leave (&music_player_bridge_type_id__volatile, music_player_bridge_type_id);
	}
	return music_player_bridge_type_id__volatile;
}


static void _vala_array_destroy (gpointer array, gint array_length, GDestroyNotify destroy_func) {
	if ((array != NULL) && (destroy_func != NULL)) {
		int i;
		for (i = 0; i < array_length; i = i + 1) {
			if (((gpointer*) array)[i] != NULL) {
				destroy_func (((gpointer*) array)[i]);
			}
		}
	}
}


static void _vala_array_free (gpointer array, gint array_length, GDestroyNotify destroy_func) {
	_vala_array_destroy (array, array_length, destroy_func);
	g_free (array);
}


static gint _vala_array_length (gpointer array) {
	int length;
	length = 0;
	if (array) {
		while (((gpointer*) array)[length]) {
			length++;
		}
	}
	return length;
}




