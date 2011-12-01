/* playlists-menu-item.c generated by valac 0.14.0, the Vala compiler
 * generated from playlists-menu-item.vala, do not modify */

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
#include <libdbusmenu-glib/client.h>
#include <libdbusmenu-glib/dbusmenu-glib.h>
#include <libdbusmenu-glib/enum-types.h>
#include <libdbusmenu-glib/menuitem-proxy.h>
#include <libdbusmenu-glib/menuitem.h>
#include <libdbusmenu-glib/server.h>
#include <libdbusmenu-glib/types.h>
#include <gee.h>
#include <common-defs.h>
#include <stdlib.h>
#include <string.h>
#include <glib/gi18n-lib.h>


#define TYPE_PLAYER_ITEM (player_item_get_type ())
#define PLAYER_ITEM(obj) (G_TYPE_CHECK_INSTANCE_CAST ((obj), TYPE_PLAYER_ITEM, PlayerItem))
#define PLAYER_ITEM_CLASS(klass) (G_TYPE_CHECK_CLASS_CAST ((klass), TYPE_PLAYER_ITEM, PlayerItemClass))
#define IS_PLAYER_ITEM(obj) (G_TYPE_CHECK_INSTANCE_TYPE ((obj), TYPE_PLAYER_ITEM))
#define IS_PLAYER_ITEM_CLASS(klass) (G_TYPE_CHECK_CLASS_TYPE ((klass), TYPE_PLAYER_ITEM))
#define PLAYER_ITEM_GET_CLASS(obj) (G_TYPE_INSTANCE_GET_CLASS ((obj), TYPE_PLAYER_ITEM, PlayerItemClass))

typedef struct _PlayerItem PlayerItem;
typedef struct _PlayerItemClass PlayerItemClass;
typedef struct _PlayerItemPrivate PlayerItemPrivate;

#define TYPE_PLAYLISTS_MENUITEM (playlists_menuitem_get_type ())
#define PLAYLISTS_MENUITEM(obj) (G_TYPE_CHECK_INSTANCE_CAST ((obj), TYPE_PLAYLISTS_MENUITEM, PlaylistsMenuitem))
#define PLAYLISTS_MENUITEM_CLASS(klass) (G_TYPE_CHECK_CLASS_CAST ((klass), TYPE_PLAYLISTS_MENUITEM, PlaylistsMenuitemClass))
#define IS_PLAYLISTS_MENUITEM(obj) (G_TYPE_CHECK_INSTANCE_TYPE ((obj), TYPE_PLAYLISTS_MENUITEM))
#define IS_PLAYLISTS_MENUITEM_CLASS(klass) (G_TYPE_CHECK_CLASS_TYPE ((klass), TYPE_PLAYLISTS_MENUITEM))
#define PLAYLISTS_MENUITEM_GET_CLASS(obj) (G_TYPE_INSTANCE_GET_CLASS ((obj), TYPE_PLAYLISTS_MENUITEM, PlaylistsMenuitemClass))

typedef struct _PlaylistsMenuitem PlaylistsMenuitem;
typedef struct _PlaylistsMenuitemClass PlaylistsMenuitemClass;
typedef struct _PlaylistsMenuitemPrivate PlaylistsMenuitemPrivate;
#define _g_object_unref0(var) ((var == NULL) ? NULL : (var = (g_object_unref (var), NULL)))

#define TYPE_PLAYER_CONTROLLER (player_controller_get_type ())
#define PLAYER_CONTROLLER(obj) (G_TYPE_CHECK_INSTANCE_CAST ((obj), TYPE_PLAYER_CONTROLLER, PlayerController))
#define PLAYER_CONTROLLER_CLASS(klass) (G_TYPE_CHECK_CLASS_CAST ((klass), TYPE_PLAYER_CONTROLLER, PlayerControllerClass))
#define IS_PLAYER_CONTROLLER(obj) (G_TYPE_CHECK_INSTANCE_TYPE ((obj), TYPE_PLAYER_CONTROLLER))
#define IS_PLAYER_CONTROLLER_CLASS(klass) (G_TYPE_CHECK_CLASS_TYPE ((klass), TYPE_PLAYER_CONTROLLER))
#define PLAYER_CONTROLLER_GET_CLASS(obj) (G_TYPE_INSTANCE_GET_CLASS ((obj), TYPE_PLAYER_CONTROLLER, PlayerControllerClass))

typedef struct _PlayerController PlayerController;
typedef struct _PlayerControllerClass PlayerControllerClass;

#define TYPE_PLAYLIST_DETAILS (playlist_details_get_type ())
typedef struct _PlaylistDetails PlaylistDetails;
typedef struct _Block1Data Block1Data;
#define _g_free0(var) (var = (g_free (var), NULL))
typedef struct _PlayerControllerPrivate PlayerControllerPrivate;

#define TYPE_MPRIS2_CONTROLLER (mpris2_controller_get_type ())
#define MPRIS2_CONTROLLER(obj) (G_TYPE_CHECK_INSTANCE_CAST ((obj), TYPE_MPRIS2_CONTROLLER, Mpris2Controller))
#define MPRIS2_CONTROLLER_CLASS(klass) (G_TYPE_CHECK_CLASS_CAST ((klass), TYPE_MPRIS2_CONTROLLER, Mpris2ControllerClass))
#define IS_MPRIS2_CONTROLLER(obj) (G_TYPE_CHECK_INSTANCE_TYPE ((obj), TYPE_MPRIS2_CONTROLLER))
#define IS_MPRIS2_CONTROLLER_CLASS(klass) (G_TYPE_CHECK_CLASS_TYPE ((klass), TYPE_MPRIS2_CONTROLLER))
#define MPRIS2_CONTROLLER_GET_CLASS(obj) (G_TYPE_INSTANCE_GET_CLASS ((obj), TYPE_MPRIS2_CONTROLLER, Mpris2ControllerClass))

typedef struct _Mpris2Controller Mpris2Controller;
typedef struct _Mpris2ControllerClass Mpris2ControllerClass;

struct _PlayerItem {
	DbusmenuMenuitem parent_instance;
	PlayerItemPrivate * priv;
};

struct _PlayerItemClass {
	DbusmenuMenuitemClass parent_class;
};

struct _PlaylistsMenuitem {
	PlayerItem parent_instance;
	PlaylistsMenuitemPrivate * priv;
	DbusmenuMenuitem* root_item;
};

struct _PlaylistsMenuitemClass {
	PlayerItemClass parent_class;
};

struct _PlaylistsMenuitemPrivate {
	GeeHashMap* current_playlists;
};

struct _PlaylistDetails {
	char* path;
	gchar* name;
	gchar* icon_path;
};

struct _Block1Data {
	int _ref_count_;
	PlaylistsMenuitem * self;
	DbusmenuMenuitem* menuitem;
};

struct _PlayerController {
	GObject parent_instance;
	PlayerControllerPrivate * priv;
	gint current_state;
	DbusmenuMenuitem* root_menu;
	GeeArrayList* custom_items;
	Mpris2Controller* mpris_bridge;
	gboolean* use_playlists;
};

struct _PlayerControllerClass {
	GObjectClass parent_class;
};


static gpointer playlists_menuitem_parent_class = NULL;

GType player_item_get_type (void) G_GNUC_CONST;
GType playlists_menuitem_get_type (void) G_GNUC_CONST;
#define PLAYLISTS_MENUITEM_GET_PRIVATE(o) (G_TYPE_INSTANCE_GET_PRIVATE ((o), TYPE_PLAYLISTS_MENUITEM, PlaylistsMenuitemPrivate))
enum  {
	PLAYLISTS_MENUITEM_DUMMY_PROPERTY
};
GType player_controller_get_type (void) G_GNUC_CONST;
PlaylistsMenuitem* playlists_menuitem_new (PlayerController* parent);
PlaylistsMenuitem* playlists_menuitem_construct (GType object_type, PlayerController* parent);
GType playlist_details_get_type (void) G_GNUC_CONST;
PlaylistDetails* playlist_details_dup (const PlaylistDetails* self);
void playlist_details_free (PlaylistDetails* self);
void playlist_details_copy (const PlaylistDetails* self, PlaylistDetails* dest);
void playlist_details_destroy (PlaylistDetails* self);
void playlists_menuitem_update (PlaylistsMenuitem* self, PlaylistDetails* playlists, int playlists_length1);
static Block1Data* block1_data_ref (Block1Data* _data1_);
static void block1_data_unref (Block1Data* _data1_);
static gboolean playlists_menuitem_already_observed (PlaylistsMenuitem* self, PlaylistDetails* new_detail);
static gboolean playlists_menuitem_is_video_related (PlaylistsMenuitem* self, PlaylistDetails* new_detail);
static gchar* playlists_menuitem_truncate_item_label_if_needs_be (PlaylistsMenuitem* self, const gchar* item_label);
static void ____lambda1_ (Block1Data* _data1_);
static void playlists_menuitem_submenu_item_activated (PlaylistsMenuitem* self, gint menu_item_id);
static void _____lambda1__dbusmenu_menuitem_item_activated (DbusmenuMenuitem* _sender, guint object, gpointer self);
void playlists_menuitem_update_individual_playlist (PlaylistsMenuitem* self, PlaylistDetails* new_detail);
void playlists_menuitem_active_playlist_update (PlaylistsMenuitem* self, PlaylistDetails* detail);
PlayerController* player_item_get_owner (PlayerItem* self);
GType mpris2_controller_get_type (void) G_GNUC_CONST;
void mpris2_controller_activate_playlist (Mpris2Controller* self, const char* path);
GeeHashSet* playlists_menuitem_attributes_format (void);
static GObject * playlists_menuitem_constructor (GType type, guint n_construct_properties, GObjectConstructParam * construct_properties);
static void playlists_menuitem_finalize (GObject* obj);


PlaylistsMenuitem* playlists_menuitem_construct (GType object_type, PlayerController* parent) {
	PlaylistsMenuitem * self = NULL;
	PlayerController* _tmp0_;
	g_return_val_if_fail (parent != NULL, NULL);
	_tmp0_ = parent;
	self = (PlaylistsMenuitem*) g_object_new (object_type, "item-type", DBUSMENU_PLAYLISTS_MENUITEM_TYPE, "owner", _tmp0_, NULL);
	return self;
}


PlaylistsMenuitem* playlists_menuitem_new (PlayerController* parent) {
	return playlists_menuitem_construct (TYPE_PLAYLISTS_MENUITEM, parent);
}


static Block1Data* block1_data_ref (Block1Data* _data1_) {
	g_atomic_int_inc (&_data1_->_ref_count_);
	return _data1_;
}


static void block1_data_unref (Block1Data* _data1_) {
	if (g_atomic_int_dec_and_test (&_data1_->_ref_count_)) {
		_g_object_unref0 (_data1_->self);
		_g_object_unref0 (_data1_->menuitem);
		g_slice_free (Block1Data, _data1_);
	}
}


static void ____lambda1_ (Block1Data* _data1_) {
	PlaylistsMenuitem * self;
	DbusmenuMenuitem* _tmp0_;
	gint _tmp1_;
	gint _tmp2_;
	self = _data1_->self;
	_tmp0_ = _data1_->menuitem;
	_tmp1_ = dbusmenu_menuitem_get_id (_tmp0_);
	_tmp2_ = _tmp1_;
	playlists_menuitem_submenu_item_activated (self, _tmp2_);
}


static void _____lambda1__dbusmenu_menuitem_item_activated (DbusmenuMenuitem* _sender, guint object, gpointer self) {
	____lambda1_ (self);
}


void playlists_menuitem_update (PlaylistsMenuitem* self, PlaylistDetails* playlists, int playlists_length1) {
	PlaylistDetails* _tmp0_;
	gint _tmp0__length1;
	g_return_if_fail (self != NULL);
	_tmp0_ = playlists;
	_tmp0__length1 = playlists_length1;
	{
		PlaylistDetails* detail_collection = NULL;
		gint detail_collection_length1 = 0;
		gint _detail_collection_size_ = 0;
		gint detail_it = 0;
		detail_collection = _tmp0_;
		detail_collection_length1 = _tmp0__length1;
		for (detail_it = 0; detail_it < _tmp0__length1; detail_it = detail_it + 1) {
			PlaylistDetails _tmp1_ = {0};
			PlaylistDetails detail = {0};
			playlist_details_copy (&detail_collection[detail_it], &_tmp1_);
			detail = _tmp1_;
			{
				Block1Data* _data1_;
				gboolean _tmp2_ = FALSE;
				PlaylistDetails _tmp3_;
				gboolean _tmp4_ = FALSE;
				gboolean _tmp7_;
				DbusmenuMenuitem* _tmp8_;
				DbusmenuMenuitem* _tmp9_;
				PlaylistDetails _tmp10_;
				const gchar* _tmp11_;
				gchar* _tmp12_ = NULL;
				gchar* _tmp13_;
				DbusmenuMenuitem* _tmp14_;
				DbusmenuMenuitem* _tmp15_;
				PlaylistDetails _tmp16_;
				const char* _tmp17_;
				DbusmenuMenuitem* _tmp18_;
				DbusmenuMenuitem* _tmp19_;
				DbusmenuMenuitem* _tmp20_;
				GeeHashMap* _tmp21_;
				DbusmenuMenuitem* _tmp22_;
				gint _tmp23_;
				gint _tmp24_;
				DbusmenuMenuitem* _tmp25_;
				DbusmenuMenuitem* _tmp26_;
				DbusmenuMenuitem* _tmp27_;
				PlaylistDetails _tmp28_;
				const gchar* _tmp29_;
				_data1_ = g_slice_new0 (Block1Data);
				_data1_->_ref_count_ = 1;
				_data1_->self = g_object_ref (self);
				_tmp3_ = detail;
				_tmp4_ = playlists_menuitem_already_observed (self, &_tmp3_);
				if (_tmp4_) {
					_tmp2_ = TRUE;
				} else {
					PlaylistDetails _tmp5_;
					gboolean _tmp6_ = FALSE;
					_tmp5_ = detail;
					_tmp6_ = playlists_menuitem_is_video_related (self, &_tmp5_);
					_tmp2_ = _tmp6_;
				}
				_tmp7_ = _tmp2_;
				if (_tmp7_) {
					playlist_details_destroy (&detail);
					block1_data_unref (_data1_);
					_data1_ = NULL;
					continue;
				}
				_tmp8_ = dbusmenu_menuitem_new ();
				_data1_->menuitem = _tmp8_;
				_tmp9_ = _data1_->menuitem;
				_tmp10_ = detail;
				_tmp11_ = _tmp10_.name;
				_tmp12_ = playlists_menuitem_truncate_item_label_if_needs_be (self, _tmp11_);
				_tmp13_ = _tmp12_;
				dbusmenu_menuitem_property_set (_tmp9_, DBUSMENU_MENUITEM_PROP_LABEL, _tmp13_);
				_g_free0 (_tmp13_);
				_tmp14_ = _data1_->menuitem;
				dbusmenu_menuitem_property_set (_tmp14_, DBUSMENU_MENUITEM_PROP_ICON_NAME, "playlist-symbolic");
				_tmp15_ = _data1_->menuitem;
				_tmp16_ = detail;
				_tmp17_ = _tmp16_.path;
				dbusmenu_menuitem_property_set (_tmp15_, DBUSMENU_PLAYLIST_MENUITEM_PATH, (const gchar*) _tmp17_);
				_tmp18_ = _data1_->menuitem;
				dbusmenu_menuitem_property_set_bool (_tmp18_, DBUSMENU_MENUITEM_PROP_VISIBLE, TRUE);
				_tmp19_ = _data1_->menuitem;
				dbusmenu_menuitem_property_set_bool (_tmp19_, DBUSMENU_MENUITEM_PROP_ENABLED, TRUE);
				_tmp20_ = _data1_->menuitem;
				g_signal_connect_data (_tmp20_, "item-activated", (GCallback) _____lambda1__dbusmenu_menuitem_item_activated, block1_data_ref (_data1_), (GClosureNotify) block1_data_unref, 0);
				_tmp21_ = self->priv->current_playlists;
				_tmp22_ = _data1_->menuitem;
				_tmp23_ = dbusmenu_menuitem_get_id (_tmp22_);
				_tmp24_ = _tmp23_;
				_tmp25_ = _data1_->menuitem;
				gee_abstract_map_set ((GeeAbstractMap*) _tmp21_, GINT_TO_POINTER (_tmp24_), _tmp25_);
				_tmp26_ = self->root_item;
				_tmp27_ = _data1_->menuitem;
				dbusmenu_menuitem_child_append (_tmp26_, _tmp27_);
				_tmp28_ = detail;
				_tmp29_ = _tmp28_.name;
				g_debug ("playlists-menu-item.vala:66: populating valid playlists %s", _tmp29_);
				playlist_details_destroy (&detail);
				block1_data_unref (_data1_);
				_data1_ = NULL;
			}
		}
	}
	{
		GeeHashMap* _tmp30_;
		GeeCollection* _tmp31_;
		GeeCollection* _tmp32_;
		GeeCollection* _tmp33_;
		GeeIterator* _tmp34_ = NULL;
		GeeIterator* _tmp35_;
		GeeIterator* _item_it;
		_tmp30_ = self->priv->current_playlists;
		_tmp31_ = gee_map_get_values ((GeeMap*) _tmp30_);
		_tmp32_ = _tmp31_;
		_tmp33_ = _tmp32_;
		_tmp34_ = gee_iterable_iterator ((GeeIterable*) _tmp33_);
		_tmp35_ = _tmp34_;
		_g_object_unref0 (_tmp33_);
		_item_it = _tmp35_;
		while (TRUE) {
			GeeIterator* _tmp36_;
			gboolean _tmp37_ = FALSE;
			GeeIterator* _tmp38_;
			gpointer _tmp39_ = NULL;
			DbusmenuMenuitem* item;
			gboolean within;
			PlaylistDetails* _tmp40_;
			gint _tmp40__length1;
			gboolean _tmp46_;
			_tmp36_ = _item_it;
			_tmp37_ = gee_iterator_next (_tmp36_);
			if (!_tmp37_) {
				break;
			}
			_tmp38_ = _item_it;
			_tmp39_ = gee_iterator_get (_tmp38_);
			item = (DbusmenuMenuitem*) _tmp39_;
			within = FALSE;
			_tmp40_ = playlists;
			_tmp40__length1 = playlists_length1;
			{
				PlaylistDetails* detail_collection = NULL;
				gint detail_collection_length1 = 0;
				gint _detail_collection_size_ = 0;
				gint detail_it = 0;
				detail_collection = _tmp40_;
				detail_collection_length1 = _tmp40__length1;
				for (detail_it = 0; detail_it < _tmp40__length1; detail_it = detail_it + 1) {
					PlaylistDetails _tmp41_ = {0};
					PlaylistDetails detail = {0};
					playlist_details_copy (&detail_collection[detail_it], &_tmp41_);
					detail = _tmp41_;
					{
						PlaylistDetails _tmp42_;
						const char* _tmp43_;
						DbusmenuMenuitem* _tmp44_;
						const gchar* _tmp45_ = NULL;
						_tmp42_ = detail;
						_tmp43_ = _tmp42_.path;
						_tmp44_ = item;
						_tmp45_ = dbusmenu_menuitem_property_get (_tmp44_, DBUSMENU_PLAYLIST_MENUITEM_PATH);
						if (g_strcmp0 (_tmp43_, _tmp45_) == 0) {
							within = TRUE;
							playlist_details_destroy (&detail);
							break;
						}
						playlist_details_destroy (&detail);
					}
				}
			}
			_tmp46_ = within;
			if (_tmp46_ == FALSE) {
				DbusmenuMenuitem* _tmp47_;
				const gchar* _tmp48_ = NULL;
				DbusmenuMenuitem* _tmp49_;
				const gchar* _tmp50_ = NULL;
				DbusmenuMenuitem* _tmp53_;
				DbusmenuMenuitem* _tmp54_;
				_tmp47_ = self->root_item;
				_tmp48_ = dbusmenu_menuitem_property_get (_tmp47_, DBUSMENU_PLAYLIST_MENUITEM_PATH);
				_tmp49_ = item;
				_tmp50_ = dbusmenu_menuitem_property_get (_tmp49_, DBUSMENU_PLAYLIST_MENUITEM_PATH);
				if (g_strcmp0 (_tmp48_, _tmp50_) == 0) {
					DbusmenuMenuitem* _tmp51_;
					const gchar* _tmp52_ = NULL;
					_tmp51_ = self->root_item;
					_tmp52_ = _ ("Choose Playlist");
					dbusmenu_menuitem_property_set (_tmp51_, DBUSMENU_MENUITEM_PROP_LABEL, _tmp52_);
				}
				_tmp53_ = self->root_item;
				_tmp54_ = item;
				dbusmenu_menuitem_child_delete (_tmp53_, _tmp54_);
			}
			_g_object_unref0 (item);
		}
		_g_object_unref0 (_item_it);
	}
}


void playlists_menuitem_update_individual_playlist (PlaylistsMenuitem* self, PlaylistDetails* new_detail) {
	DbusmenuMenuitem* _tmp19_;
	const gchar* _tmp20_ = NULL;
	PlaylistDetails _tmp21_;
	const char* _tmp22_;
	g_return_if_fail (self != NULL);
	g_return_if_fail (new_detail != NULL);
	{
		GeeHashMap* _tmp0_;
		GeeCollection* _tmp1_;
		GeeCollection* _tmp2_;
		GeeCollection* _tmp3_;
		GeeIterator* _tmp4_ = NULL;
		GeeIterator* _tmp5_;
		GeeIterator* _item_it;
		_tmp0_ = self->priv->current_playlists;
		_tmp1_ = gee_map_get_values ((GeeMap*) _tmp0_);
		_tmp2_ = _tmp1_;
		_tmp3_ = _tmp2_;
		_tmp4_ = gee_iterable_iterator ((GeeIterable*) _tmp3_);
		_tmp5_ = _tmp4_;
		_g_object_unref0 (_tmp3_);
		_item_it = _tmp5_;
		while (TRUE) {
			GeeIterator* _tmp6_;
			gboolean _tmp7_ = FALSE;
			GeeIterator* _tmp8_;
			gpointer _tmp9_ = NULL;
			DbusmenuMenuitem* item;
			PlaylistDetails _tmp10_;
			const char* _tmp11_;
			DbusmenuMenuitem* _tmp12_;
			const gchar* _tmp13_ = NULL;
			_tmp6_ = _item_it;
			_tmp7_ = gee_iterator_next (_tmp6_);
			if (!_tmp7_) {
				break;
			}
			_tmp8_ = _item_it;
			_tmp9_ = gee_iterator_get (_tmp8_);
			item = (DbusmenuMenuitem*) _tmp9_;
			_tmp10_ = *new_detail;
			_tmp11_ = _tmp10_.path;
			_tmp12_ = item;
			_tmp13_ = dbusmenu_menuitem_property_get (_tmp12_, DBUSMENU_PLAYLIST_MENUITEM_PATH);
			if (g_strcmp0 (_tmp11_, _tmp13_) == 0) {
				DbusmenuMenuitem* _tmp14_;
				PlaylistDetails _tmp15_;
				const gchar* _tmp16_;
				gchar* _tmp17_ = NULL;
				gchar* _tmp18_;
				_tmp14_ = item;
				_tmp15_ = *new_detail;
				_tmp16_ = _tmp15_.name;
				_tmp17_ = playlists_menuitem_truncate_item_label_if_needs_be (self, _tmp16_);
				_tmp18_ = _tmp17_;
				dbusmenu_menuitem_property_set (_tmp14_, DBUSMENU_MENUITEM_PROP_LABEL, _tmp18_);
				_g_free0 (_tmp18_);
			}
			_g_object_unref0 (item);
		}
		_g_object_unref0 (_item_it);
	}
	_tmp19_ = self->root_item;
	_tmp20_ = dbusmenu_menuitem_property_get (_tmp19_, DBUSMENU_PLAYLIST_MENUITEM_PATH);
	_tmp21_ = *new_detail;
	_tmp22_ = _tmp21_.path;
	if (g_strcmp0 (_tmp20_, _tmp22_) == 0) {
		DbusmenuMenuitem* _tmp23_;
		PlaylistDetails _tmp24_;
		const gchar* _tmp25_;
		gchar* _tmp26_ = NULL;
		gchar* _tmp27_;
		_tmp23_ = self->root_item;
		_tmp24_ = *new_detail;
		_tmp25_ = _tmp24_.name;
		_tmp26_ = playlists_menuitem_truncate_item_label_if_needs_be (self, _tmp25_);
		_tmp27_ = _tmp26_;
		dbusmenu_menuitem_property_set (_tmp23_, DBUSMENU_MENUITEM_PROP_LABEL, _tmp27_);
		_g_free0 (_tmp27_);
	}
}


static gboolean playlists_menuitem_already_observed (PlaylistsMenuitem* self, PlaylistDetails* new_detail) {
	gboolean result = FALSE;
	g_return_val_if_fail (self != NULL, FALSE);
	g_return_val_if_fail (new_detail != NULL, FALSE);
	{
		GeeHashMap* _tmp0_;
		GeeCollection* _tmp1_;
		GeeCollection* _tmp2_;
		GeeCollection* _tmp3_;
		GeeIterator* _tmp4_ = NULL;
		GeeIterator* _tmp5_;
		GeeIterator* _item_it;
		_tmp0_ = self->priv->current_playlists;
		_tmp1_ = gee_map_get_values ((GeeMap*) _tmp0_);
		_tmp2_ = _tmp1_;
		_tmp3_ = _tmp2_;
		_tmp4_ = gee_iterable_iterator ((GeeIterable*) _tmp3_);
		_tmp5_ = _tmp4_;
		_g_object_unref0 (_tmp3_);
		_item_it = _tmp5_;
		while (TRUE) {
			GeeIterator* _tmp6_;
			gboolean _tmp7_ = FALSE;
			GeeIterator* _tmp8_;
			gpointer _tmp9_ = NULL;
			DbusmenuMenuitem* item;
			DbusmenuMenuitem* _tmp10_;
			const gchar* _tmp11_ = NULL;
			gchar* _tmp12_;
			gchar* path;
			PlaylistDetails _tmp13_;
			const char* _tmp14_;
			const gchar* _tmp15_;
			_tmp6_ = _item_it;
			_tmp7_ = gee_iterator_next (_tmp6_);
			if (!_tmp7_) {
				break;
			}
			_tmp8_ = _item_it;
			_tmp9_ = gee_iterator_get (_tmp8_);
			item = (DbusmenuMenuitem*) _tmp9_;
			_tmp10_ = item;
			_tmp11_ = dbusmenu_menuitem_property_get (_tmp10_, DBUSMENU_PLAYLIST_MENUITEM_PATH);
			_tmp12_ = g_strdup (_tmp11_);
			path = _tmp12_;
			_tmp13_ = *new_detail;
			_tmp14_ = _tmp13_.path;
			_tmp15_ = path;
			if (g_strcmp0 (_tmp14_, _tmp15_) == 0) {
				result = TRUE;
				_g_free0 (path);
				_g_object_unref0 (item);
				_g_object_unref0 (_item_it);
				return result;
			}
			_g_free0 (path);
			_g_object_unref0 (item);
		}
		_g_object_unref0 (_item_it);
	}
	result = FALSE;
	return result;
}


static gboolean string_contains (const gchar* self, const gchar* needle) {
	gboolean result = FALSE;
	const gchar* _tmp0_;
	gchar* _tmp1_ = NULL;
	g_return_val_if_fail (self != NULL, FALSE);
	g_return_val_if_fail (needle != NULL, FALSE);
	_tmp0_ = needle;
	_tmp1_ = strstr ((gchar*) self, (gchar*) _tmp0_);
	result = _tmp1_ != NULL;
	return result;
}


static gboolean playlists_menuitem_is_video_related (PlaylistsMenuitem* self, PlaylistDetails* new_detail) {
	gboolean result = FALSE;
	PlaylistDetails _tmp0_;
	const char* _tmp1_;
	gchar* _tmp2_;
	gchar* location;
	const gchar* _tmp3_;
	gboolean _tmp4_ = FALSE;
	g_return_val_if_fail (self != NULL, FALSE);
	g_return_val_if_fail (new_detail != NULL, FALSE);
	_tmp0_ = *new_detail;
	_tmp1_ = _tmp0_.path;
	_tmp2_ = g_strdup ((const gchar*) _tmp1_);
	location = _tmp2_;
	_tmp3_ = location;
	_tmp4_ = string_contains (_tmp3_, "/VideoLibrarySource/");
	if (_tmp4_) {
		result = TRUE;
		_g_free0 (location);
		return result;
	}
	result = FALSE;
	_g_free0 (location);
	return result;
}


void playlists_menuitem_active_playlist_update (PlaylistsMenuitem* self, PlaylistDetails* detail) {
	PlaylistDetails _tmp0_;
	const gchar* _tmp1_;
	gchar* _tmp2_;
	gchar* update;
	const gchar* _tmp3_;
	DbusmenuMenuitem* _tmp6_;
	const gchar* _tmp7_;
	gchar* _tmp8_ = NULL;
	gchar* _tmp9_;
	DbusmenuMenuitem* _tmp10_;
	PlaylistDetails _tmp11_;
	const char* _tmp12_;
	g_return_if_fail (self != NULL);
	g_return_if_fail (detail != NULL);
	_tmp0_ = *detail;
	_tmp1_ = _tmp0_.name;
	_tmp2_ = g_strdup (_tmp1_);
	update = _tmp2_;
	_tmp3_ = update;
	if (g_strcmp0 (_tmp3_, "") == 0) {
		const gchar* _tmp4_ = NULL;
		gchar* _tmp5_;
		_tmp4_ = _ ("Choose Playlist");
		_tmp5_ = g_strdup (_tmp4_);
		_g_free0 (update);
		update = _tmp5_;
	}
	_tmp6_ = self->root_item;
	_tmp7_ = update;
	_tmp8_ = playlists_menuitem_truncate_item_label_if_needs_be (self, _tmp7_);
	_tmp9_ = _tmp8_;
	dbusmenu_menuitem_property_set (_tmp6_, DBUSMENU_MENUITEM_PROP_LABEL, _tmp9_);
	_g_free0 (_tmp9_);
	_tmp10_ = self->root_item;
	_tmp11_ = *detail;
	_tmp12_ = _tmp11_.path;
	dbusmenu_menuitem_property_set (_tmp10_, DBUSMENU_PLAYLIST_MENUITEM_PATH, (const gchar*) _tmp12_);
	_g_free0 (update);
}


static void playlists_menuitem_submenu_item_activated (PlaylistsMenuitem* self, gint menu_item_id) {
	GeeHashMap* _tmp0_;
	gint _tmp1_;
	gboolean _tmp2_ = FALSE;
	PlayerController* _tmp4_;
	PlayerController* _tmp5_;
	Mpris2Controller* _tmp6_;
	GeeHashMap* _tmp7_;
	gint _tmp8_;
	gpointer _tmp9_ = NULL;
	DbusmenuMenuitem* _tmp10_;
	const gchar* _tmp11_ = NULL;
	g_return_if_fail (self != NULL);
	_tmp0_ = self->priv->current_playlists;
	_tmp1_ = menu_item_id;
	_tmp2_ = gee_abstract_map_has_key ((GeeAbstractMap*) _tmp0_, GINT_TO_POINTER (_tmp1_));
	if (!_tmp2_) {
		gint _tmp3_;
		_tmp3_ = menu_item_id;
		g_warning ("playlists-menu-item.vala:129: item %i was activated but we don't have " \
"a corresponding playlist", _tmp3_);
		return;
	}
	_tmp4_ = player_item_get_owner ((PlayerItem*) self);
	_tmp5_ = _tmp4_;
	_tmp6_ = _tmp5_->mpris_bridge;
	_tmp7_ = self->priv->current_playlists;
	_tmp8_ = menu_item_id;
	_tmp9_ = gee_abstract_map_get ((GeeAbstractMap*) _tmp7_, GINT_TO_POINTER (_tmp8_));
	_tmp10_ = (DbusmenuMenuitem*) _tmp9_;
	_tmp11_ = dbusmenu_menuitem_property_get (_tmp10_, DBUSMENU_PLAYLIST_MENUITEM_PATH);
	mpris2_controller_activate_playlist (_tmp6_, (const char*) _tmp11_);
	_g_object_unref0 (_tmp10_);
}


static gchar* string_slice (const gchar* self, glong start, glong end) {
	gchar* result = NULL;
	gint _tmp0_;
	gint _tmp1_;
	glong string_length;
	glong _tmp2_;
	glong _tmp5_;
	gboolean _tmp8_ = FALSE;
	glong _tmp9_;
	gboolean _tmp12_;
	gboolean _tmp13_ = FALSE;
	glong _tmp14_;
	gboolean _tmp17_;
	glong _tmp18_;
	glong _tmp19_;
	glong _tmp20_;
	glong _tmp21_;
	glong _tmp22_;
	gchar* _tmp23_ = NULL;
	g_return_val_if_fail (self != NULL, NULL);
	_tmp0_ = strlen (self);
	_tmp1_ = _tmp0_;
	string_length = (glong) _tmp1_;
	_tmp2_ = start;
	if (_tmp2_ < ((glong) 0)) {
		glong _tmp3_;
		glong _tmp4_;
		_tmp3_ = string_length;
		_tmp4_ = start;
		start = _tmp3_ + _tmp4_;
	}
	_tmp5_ = end;
	if (_tmp5_ < ((glong) 0)) {
		glong _tmp6_;
		glong _tmp7_;
		_tmp6_ = string_length;
		_tmp7_ = end;
		end = _tmp6_ + _tmp7_;
	}
	_tmp9_ = start;
	if (_tmp9_ >= ((glong) 0)) {
		glong _tmp10_;
		glong _tmp11_;
		_tmp10_ = start;
		_tmp11_ = string_length;
		_tmp8_ = _tmp10_ <= _tmp11_;
	} else {
		_tmp8_ = FALSE;
	}
	_tmp12_ = _tmp8_;
	g_return_val_if_fail (_tmp12_, NULL);
	_tmp14_ = end;
	if (_tmp14_ >= ((glong) 0)) {
		glong _tmp15_;
		glong _tmp16_;
		_tmp15_ = end;
		_tmp16_ = string_length;
		_tmp13_ = _tmp15_ <= _tmp16_;
	} else {
		_tmp13_ = FALSE;
	}
	_tmp17_ = _tmp13_;
	g_return_val_if_fail (_tmp17_, NULL);
	_tmp18_ = start;
	_tmp19_ = end;
	g_return_val_if_fail (_tmp18_ <= _tmp19_, NULL);
	_tmp20_ = start;
	_tmp21_ = end;
	_tmp22_ = start;
	_tmp23_ = g_strndup (((gchar*) self) + _tmp20_, (gsize) (_tmp21_ - _tmp22_));
	result = _tmp23_;
	return result;
}


static gchar* playlists_menuitem_truncate_item_label_if_needs_be (PlaylistsMenuitem* self, const gchar* item_label) {
	gchar* result = NULL;
	const gchar* _tmp0_;
	gchar* _tmp1_;
	gchar* _result_;
	const gchar* _tmp2_;
	gint _tmp3_ = 0;
	g_return_val_if_fail (self != NULL, NULL);
	g_return_val_if_fail (item_label != NULL, NULL);
	_tmp0_ = item_label;
	_tmp1_ = g_strdup (_tmp0_);
	_result_ = _tmp1_;
	_tmp2_ = item_label;
	_tmp3_ = g_utf8_strlen (_tmp2_, (gssize) (-1));
	if (_tmp3_ > 17) {
		const gchar* _tmp4_;
		gchar* _tmp5_ = NULL;
		const gchar* _tmp6_;
		gchar* _tmp7_;
		_tmp4_ = item_label;
		_tmp5_ = string_slice (_tmp4_, (glong) 0, (glong) 15);
		_g_free0 (_result_);
		_result_ = _tmp5_;
		_tmp6_ = _result_;
		_tmp7_ = g_strconcat (_tmp6_, "…", NULL);
		_g_free0 (_result_);
		_result_ = _tmp7_;
	}
	result = _result_;
	return result;
}


GeeHashSet* playlists_menuitem_attributes_format (void) {
	GeeHashSet* result = NULL;
	GeeHashSet* _tmp0_;
	GeeHashSet* attrs;
	_tmp0_ = gee_hash_set_new (G_TYPE_STRING, (GBoxedCopyFunc) g_strdup, g_free, NULL, NULL);
	attrs = _tmp0_;
	gee_abstract_collection_add ((GeeAbstractCollection*) attrs, DBUSMENU_PLAYLISTS_MENUITEM_TITLE);
	gee_abstract_collection_add ((GeeAbstractCollection*) attrs, DBUSMENU_PLAYLISTS_MENUITEM_PLAYLISTS);
	result = attrs;
	return result;
}


static GObject * playlists_menuitem_constructor (GType type, guint n_construct_properties, GObjectConstructParam * construct_properties) {
	GObject * obj;
	GObjectClass * parent_class;
	PlaylistsMenuitem * self;
	GeeHashMap* _tmp0_;
	DbusmenuMenuitem* _tmp1_;
	DbusmenuMenuitem* _tmp2_;
	const gchar* _tmp3_ = NULL;
	DbusmenuMenuitem* _tmp4_;
	parent_class = G_OBJECT_CLASS (playlists_menuitem_parent_class);
	obj = parent_class->constructor (type, n_construct_properties, construct_properties);
	self = PLAYLISTS_MENUITEM (obj);
	_tmp0_ = gee_hash_map_new (G_TYPE_INT, NULL, NULL, dbusmenu_menuitem_get_type (), (GBoxedCopyFunc) g_object_ref, g_object_unref, NULL, NULL, NULL);
	_g_object_unref0 (self->priv->current_playlists);
	self->priv->current_playlists = _tmp0_;
	_tmp1_ = dbusmenu_menuitem_new ();
	_g_object_unref0 (self->root_item);
	self->root_item = _tmp1_;
	_tmp2_ = self->root_item;
	_tmp3_ = _ ("Choose Playlist");
	dbusmenu_menuitem_property_set (_tmp2_, DBUSMENU_MENUITEM_PROP_LABEL, _tmp3_);
	_tmp4_ = self->root_item;
	dbusmenu_menuitem_property_set (_tmp4_, DBUSMENU_PLAYLIST_MENUITEM_PATH, "");
	return obj;
}


static void playlists_menuitem_class_init (PlaylistsMenuitemClass * klass) {
	playlists_menuitem_parent_class = g_type_class_peek_parent (klass);
	g_type_class_add_private (klass, sizeof (PlaylistsMenuitemPrivate));
	G_OBJECT_CLASS (klass)->constructor = playlists_menuitem_constructor;
	G_OBJECT_CLASS (klass)->finalize = playlists_menuitem_finalize;
}


static void playlists_menuitem_instance_init (PlaylistsMenuitem * self) {
	self->priv = PLAYLISTS_MENUITEM_GET_PRIVATE (self);
}


static void playlists_menuitem_finalize (GObject* obj) {
	PlaylistsMenuitem * self;
	self = PLAYLISTS_MENUITEM (obj);
	_g_object_unref0 (self->priv->current_playlists);
	_g_object_unref0 (self->root_item);
	G_OBJECT_CLASS (playlists_menuitem_parent_class)->finalize (obj);
}


GType playlists_menuitem_get_type (void) {
	static volatile gsize playlists_menuitem_type_id__volatile = 0;
	if (g_once_init_enter (&playlists_menuitem_type_id__volatile)) {
		static const GTypeInfo g_define_type_info = { sizeof (PlaylistsMenuitemClass), (GBaseInitFunc) NULL, (GBaseFinalizeFunc) NULL, (GClassInitFunc) playlists_menuitem_class_init, (GClassFinalizeFunc) NULL, NULL, sizeof (PlaylistsMenuitem), 0, (GInstanceInitFunc) playlists_menuitem_instance_init, NULL };
		GType playlists_menuitem_type_id;
		playlists_menuitem_type_id = g_type_register_static (TYPE_PLAYER_ITEM, "PlaylistsMenuitem", &g_define_type_info, 0);
		g_once_init_leave (&playlists_menuitem_type_id__volatile, playlists_menuitem_type_id);
	}
	return playlists_menuitem_type_id__volatile;
}



