/* totem-rotation-plugin.c generated by valac 0.22.0, the Vala compiler
 * generated from totem-rotation-plugin.vala, do not modify */

/*
 * Copyright (C) Simon Wenner 2011 <simon@wenner.ch>
 *
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 2 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU Library General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, write to the Free Software
 * Foundation, Inc., 51 Franklin Street, Fifth Floor Boston, MA 02110-1301,  USA
 */

#include <glib.h>
#include <glib-object.h>
#include <stdlib.h>
#include <string.h>
#include <libpeas/peas.h>
#include "bacon-video-widget.h"
#include <gtk/gtk.h>
#include <totem.h>
#include <glib/gi18n-lib.h>
#include <gio/gio.h>


#define TYPE_ROTATION_PLUGIN (rotation_plugin_get_type ())
#define ROTATION_PLUGIN(obj) (G_TYPE_CHECK_INSTANCE_CAST ((obj), TYPE_ROTATION_PLUGIN, RotationPlugin))
#define ROTATION_PLUGIN_CLASS(klass) (G_TYPE_CHECK_CLASS_CAST ((klass), TYPE_ROTATION_PLUGIN, RotationPluginClass))
#define IS_ROTATION_PLUGIN(obj) (G_TYPE_CHECK_INSTANCE_TYPE ((obj), TYPE_ROTATION_PLUGIN))
#define IS_ROTATION_PLUGIN_CLASS(klass) (G_TYPE_CHECK_CLASS_TYPE ((klass), TYPE_ROTATION_PLUGIN))
#define ROTATION_PLUGIN_GET_CLASS(obj) (G_TYPE_INSTANCE_GET_CLASS ((obj), TYPE_ROTATION_PLUGIN, RotationPluginClass))

typedef struct _RotationPlugin RotationPlugin;
typedef struct _RotationPluginClass RotationPluginClass;
typedef struct _RotationPluginPrivate RotationPluginPrivate;
#define _g_object_unref0(var) ((var == NULL) ? NULL : (var = (g_object_unref (var), NULL)))
#define _g_free0(var) (var = (g_free (var), NULL))
#define _g_error_free0(var) ((var == NULL) ? NULL : (var = (g_error_free (var), NULL)))
typedef struct _RotationPluginStoreStateData RotationPluginStoreStateData;
typedef struct _RotationPluginTryRestoreStateData RotationPluginTryRestoreStateData;

struct _RotationPlugin {
	GObject parent_instance;
	RotationPluginPrivate * priv;
};

struct _RotationPluginClass {
	GObjectClass parent_class;
};

struct _RotationPluginPrivate {
	GObject* _object;
	BaconVideoWidget* bvw;
	guint ui_id;
	GtkActionGroup* action_group;
};

struct _RotationPluginStoreStateData {
	int _state_;
	GObject* _source_object_;
	GAsyncResult* _res_;
	GSimpleAsyncResult* _async_result;
	RotationPlugin* self;
	TotemObject* t;
	GObject* _tmp0_;
	GObject* _tmp1_;
	gchar* mrl;
	TotemObject* _tmp2_;
	gchar* _tmp3_;
	const gchar* _tmp4_;
	GFile* file;
	const gchar* _tmp5_;
	GFile* _tmp6_;
	BvwRotation rotation;
	GFileInfo* file_info;
	GFile* _tmp7_;
	GFileInfo* _tmp8_;
	gchar* state_str;
	gchar* _tmp9_;
	BaconVideoWidget* _tmp10_;
	BvwRotation _tmp11_;
	BvwRotation _tmp12_;
	BvwRotation _tmp13_;
	gchar* _tmp14_;
	GFileInfo* _tmp15_;
	const gchar* _tmp16_;
	GFile* _tmp17_;
	GFileInfo* _tmp18_;
	GError* e;
	GError* _tmp19_;
	const gchar* _tmp20_;
	GError * _inner_error_;
};

struct _RotationPluginTryRestoreStateData {
	int _state_;
	GObject* _source_object_;
	GAsyncResult* _res_;
	GSimpleAsyncResult* _async_result;
	RotationPlugin* self;
	gchar* mrl;
	GFile* file;
	const gchar* _tmp0_;
	GFile* _tmp1_;
	gboolean _tmp2_;
	GFile* _tmp3_;
	gboolean _tmp4_;
	GFile* _tmp5_;
	gboolean _tmp6_;
	gboolean _tmp7_;
	GFileInfo* file_info;
	GFile* _tmp8_;
	GFileInfo* _tmp9_;
	gchar* state_str;
	GFileInfo* _tmp10_;
	const gchar* _tmp11_;
	gchar* _tmp12_;
	const gchar* _tmp13_;
	gint state;
	const gchar* _tmp14_;
	guint64 _tmp15_;
	BaconVideoWidget* _tmp16_;
	gint _tmp17_;
	GError* e;
	GError* _tmp18_;
	const gchar* _tmp19_;
	GError * _inner_error_;
};


static gpointer rotation_plugin_parent_class = NULL;
static PeasActivatableInterface* rotation_plugin_peas_activatable_parent_iface = NULL;
static GType rotation_plugin_type_id = 0;

#define GIO_ROTATION_FILE_ATTRIBUTE "metadata::totem::rotation"
GType rotation_plugin_get_type (void) G_GNUC_CONST;
GType rotation_plugin_register_type (GTypeModule * module);
#define ROTATION_PLUGIN_GET_PRIVATE(o) (G_TYPE_INSTANCE_GET_PRIVATE ((o), TYPE_ROTATION_PLUGIN, RotationPluginPrivate))
enum  {
	ROTATION_PLUGIN_DUMMY_PROPERTY,
	ROTATION_PLUGIN_OBJECT
};
#define ROTATION_PLUGIN_STATE_COUNT 4
static void rotation_plugin_real_activate (PeasActivatable* base);
static void rotation_plugin_cb_rotate_right (RotationPlugin* self);
static void _rotation_plugin_cb_rotate_right_gtk_action_activate (GtkAction* _sender, gpointer self);
static void rotation_plugin_cb_rotate_left (RotationPlugin* self);
static void _rotation_plugin_cb_rotate_left_gtk_action_activate (GtkAction* _sender, gpointer self);
static void rotation_plugin_try_restore_state (RotationPlugin* self, const gchar* mrl, GAsyncReadyCallback _callback_, gpointer _user_data_);
static void rotation_plugin_try_restore_state_finish (RotationPlugin* self, GAsyncResult* _res_);
static void rotation_plugin_cb_file_closed (RotationPlugin* self);
static void _rotation_plugin_cb_file_closed_totem_object_file_closed (TotemObject* _sender, gpointer self);
static void rotation_plugin_cb_file_opened (RotationPlugin* self, const gchar* mrl);
static void _rotation_plugin_cb_file_opened_totem_object_file_opened (TotemObject* _sender, const gchar* mrl, gpointer self);
static void rotation_plugin_real_deactivate (PeasActivatable* base);
static void rotation_plugin_real_update_state (PeasActivatable* base);
static void rotation_plugin_store_state (RotationPlugin* self, GAsyncReadyCallback _callback_, gpointer _user_data_);
static void rotation_plugin_store_state_finish (RotationPlugin* self, GAsyncResult* _res_);
static void rotation_plugin_store_state_data_free (gpointer _data);
static gboolean rotation_plugin_store_state_co (RotationPluginStoreStateData* _data_);
static void rotation_plugin_store_state_ready (GObject* source_object, GAsyncResult* _res_, gpointer _user_data_);
static void rotation_plugin_try_restore_state_data_free (gpointer _data);
static gboolean rotation_plugin_try_restore_state_co (RotationPluginTryRestoreStateData* _data_);
static void rotation_plugin_try_restore_state_ready (GObject* source_object, GAsyncResult* _res_, gpointer _user_data_);
RotationPlugin* rotation_plugin_new (void);
RotationPlugin* rotation_plugin_construct (GType object_type);
static void rotation_plugin_finalize (GObject* obj);
static void _vala_rotation_plugin_get_property (GObject * object, guint property_id, GValue * value, GParamSpec * pspec);
static void _vala_rotation_plugin_set_property (GObject * object, guint property_id, const GValue * value, GParamSpec * pspec);
void peas_register_types (GTypeModule* module);


static void _rotation_plugin_cb_rotate_right_gtk_action_activate (GtkAction* _sender, gpointer self) {
	rotation_plugin_cb_rotate_right (self);
}


static void _rotation_plugin_cb_rotate_left_gtk_action_activate (GtkAction* _sender, gpointer self) {
	rotation_plugin_cb_rotate_left (self);
}


static void _rotation_plugin_cb_file_closed_totem_object_file_closed (TotemObject* _sender, gpointer self) {
	rotation_plugin_cb_file_closed (self);
}


static void _rotation_plugin_cb_file_opened_totem_object_file_opened (TotemObject* _sender, const gchar* mrl, gpointer self) {
	rotation_plugin_cb_file_opened (self, mrl);
}


static void rotation_plugin_real_activate (PeasActivatable* base) {
	RotationPlugin * self;
	TotemObject* t = NULL;
	GObject* _tmp0_ = NULL;
	GObject* _tmp1_ = NULL;
	gchar* mrl = NULL;
	TotemObject* _tmp2_ = NULL;
	gchar* _tmp3_ = NULL;
	TotemObject* _tmp4_ = NULL;
	GtkWidget* _tmp5_ = NULL;
	BaconVideoWidget* _tmp6_ = NULL;
	GtkUIManager* ui_manager = NULL;
	TotemObject* _tmp7_ = NULL;
	GtkUIManager* _tmp8_ = NULL;
	GtkUIManager* _tmp9_ = NULL;
	guint _tmp10_ = 0U;
	GtkUIManager* _tmp11_ = NULL;
	guint _tmp12_ = 0U;
	GtkUIManager* _tmp13_ = NULL;
	guint _tmp14_ = 0U;
	GtkAction* rotate_right = NULL;
	const gchar* _tmp15_ = NULL;
	GtkAction* _tmp16_ = NULL;
	GtkAction* _tmp17_ = NULL;
	GtkAction* rotate_left = NULL;
	const gchar* _tmp18_ = NULL;
	GtkAction* _tmp19_ = NULL;
	GtkAction* _tmp20_ = NULL;
	GtkActionGroup* _tmp21_ = NULL;
	GtkActionGroup* _tmp22_ = NULL;
	GtkAction* _tmp23_ = NULL;
	GtkActionGroup* _tmp24_ = NULL;
	GtkAction* _tmp25_ = NULL;
	const gchar* _tmp26_ = NULL;
	GtkUIManager* _tmp28_ = NULL;
	GtkActionGroup* _tmp29_ = NULL;
	const gchar* _tmp30_ = NULL;
	TotemObject* _tmp32_ = NULL;
	TotemObject* _tmp33_ = NULL;
	self = (RotationPlugin*) base;
	g_object_get ((PeasActivatable*) self, "object", &_tmp0_, NULL);
	_tmp1_ = _tmp0_;
	t = G_TYPE_CHECK_INSTANCE_CAST (_tmp1_, totem_object_get_type (), TotemObject);
	_tmp2_ = t;
	_tmp3_ = totem_object_get_current_mrl (_tmp2_);
	mrl = _tmp3_;
	_tmp4_ = t;
	_tmp5_ = totem_object_get_video_widget (_tmp4_);
	_tmp6_ = G_TYPE_CHECK_INSTANCE_TYPE (_tmp5_, BACON_TYPE_VIDEO_WIDGET) ? ((BaconVideoWidget*) _tmp5_) : NULL;
	if (_tmp6_ == NULL) {
		_g_object_unref0 (_tmp5_);
	}
	_g_object_unref0 (self->priv->bvw);
	self->priv->bvw = _tmp6_;
	_tmp7_ = t;
	_tmp8_ = totem_object_get_ui_manager (_tmp7_);
	ui_manager = _tmp8_;
	_tmp9_ = ui_manager;
	_tmp10_ = gtk_ui_manager_new_merge_id (_tmp9_);
	self->priv->ui_id = _tmp10_;
	_tmp11_ = ui_manager;
	_tmp12_ = self->priv->ui_id;
	gtk_ui_manager_add_ui (_tmp11_, _tmp12_, "/ui/tmw-menubar/view/next-angle", "rotate-left", "rotate-left", GTK_UI_MANAGER_AUTO, FALSE);
	_tmp13_ = ui_manager;
	_tmp14_ = self->priv->ui_id;
	gtk_ui_manager_add_ui (_tmp13_, _tmp14_, "/ui/tmw-menubar/view/next-angle", "rotate-right", "rotate-right", GTK_UI_MANAGER_AUTO, FALSE);
	_tmp15_ = _ ("_Rotate Clockwise");
	_tmp16_ = gtk_action_new ("rotate-right", _tmp15_, NULL, NULL);
	rotate_right = _tmp16_;
	_tmp17_ = rotate_right;
	g_signal_connect_object (_tmp17_, "activate", (GCallback) _rotation_plugin_cb_rotate_right_gtk_action_activate, self, 0);
	_tmp18_ = _ ("Rotate Counterc_lockwise");
	_tmp19_ = gtk_action_new ("rotate-left", _tmp18_, NULL, NULL);
	rotate_left = _tmp19_;
	_tmp20_ = rotate_left;
	g_signal_connect_object (_tmp20_, "activate", (GCallback) _rotation_plugin_cb_rotate_left_gtk_action_activate, self, 0);
	_tmp21_ = gtk_action_group_new ("RotationActions");
	_g_object_unref0 (self->priv->action_group);
	self->priv->action_group = _tmp21_;
	_tmp22_ = self->priv->action_group;
	_tmp23_ = rotate_right;
	gtk_action_group_add_action_with_accel (_tmp22_, _tmp23_, "<ctrl>R");
	_tmp24_ = self->priv->action_group;
	_tmp25_ = rotate_left;
	gtk_action_group_add_action_with_accel (_tmp24_, _tmp25_, "<ctrl><shift>R");
	_tmp26_ = mrl;
	if (_tmp26_ == NULL) {
		GtkActionGroup* _tmp27_ = NULL;
		_tmp27_ = self->priv->action_group;
		gtk_action_group_set_sensitive (_tmp27_, FALSE);
	}
	_tmp28_ = ui_manager;
	_tmp29_ = self->priv->action_group;
	gtk_ui_manager_insert_action_group (_tmp28_, _tmp29_, 0);
	_tmp30_ = mrl;
	if (_tmp30_ != NULL) {
		const gchar* _tmp31_ = NULL;
		_tmp31_ = mrl;
		rotation_plugin_try_restore_state (self, _tmp31_, NULL, NULL);
	}
	_tmp32_ = t;
	g_signal_connect_object (_tmp32_, "file-closed", (GCallback) _rotation_plugin_cb_file_closed_totem_object_file_closed, self, 0);
	_tmp33_ = t;
	g_signal_connect_object (_tmp33_, "file-opened", (GCallback) _rotation_plugin_cb_file_opened_totem_object_file_opened, self, 0);
	_g_object_unref0 (rotate_left);
	_g_object_unref0 (rotate_right);
	_g_free0 (mrl);
	_g_object_unref0 (t);
}


static void rotation_plugin_real_deactivate (PeasActivatable* base) {
	RotationPlugin * self;
	TotemObject* t = NULL;
	GObject* _tmp0_ = NULL;
	GObject* _tmp1_ = NULL;
	guint _tmp2_ = 0U;
	guint _tmp3_ = 0U;
	GtkUIManager* ui_manager = NULL;
	GtkUIManager* _tmp4_ = NULL;
	guint _tmp5_ = 0U;
	GtkActionGroup* _tmp6_ = NULL;
	BaconVideoWidget* _tmp7_ = NULL;
	self = (RotationPlugin*) base;
	g_object_get ((PeasActivatable*) self, "object", &_tmp0_, NULL);
	_tmp1_ = _tmp0_;
	t = G_TYPE_CHECK_INSTANCE_CAST (_tmp1_, totem_object_get_type (), TotemObject);
	g_signal_parse_name ("file-closed", totem_object_get_type (), &_tmp2_, NULL, FALSE);
	g_signal_handlers_disconnect_matched (t, G_SIGNAL_MATCH_ID | G_SIGNAL_MATCH_FUNC | G_SIGNAL_MATCH_DATA, _tmp2_, 0, NULL, (GCallback) _rotation_plugin_cb_file_closed_totem_object_file_closed, self);
	g_signal_parse_name ("file-opened", totem_object_get_type (), &_tmp3_, NULL, FALSE);
	g_signal_handlers_disconnect_matched (t, G_SIGNAL_MATCH_ID | G_SIGNAL_MATCH_FUNC | G_SIGNAL_MATCH_DATA, _tmp3_, 0, NULL, (GCallback) _rotation_plugin_cb_file_opened_totem_object_file_opened, self);
	_tmp4_ = totem_object_get_ui_manager (t);
	ui_manager = _tmp4_;
	_tmp5_ = self->priv->ui_id;
	gtk_ui_manager_remove_ui (ui_manager, _tmp5_);
	_tmp6_ = self->priv->action_group;
	gtk_ui_manager_remove_action_group (ui_manager, _tmp6_);
	_tmp7_ = self->priv->bvw;
	bacon_video_widget_set_rotation (_tmp7_, BVW_ROTATION_R_ZERO);
	_g_object_unref0 (t);
}


static void rotation_plugin_real_update_state (PeasActivatable* base) {
	RotationPlugin * self;
	self = (RotationPlugin*) base;
}


static void rotation_plugin_cb_rotate_left (RotationPlugin* self) {
	gint state = 0;
	BaconVideoWidget* _tmp0_ = NULL;
	BvwRotation _tmp1_ = 0;
	BaconVideoWidget* _tmp2_ = NULL;
	g_return_if_fail (self != NULL);
	_tmp0_ = self->priv->bvw;
	_tmp1_ = bacon_video_widget_get_rotation (_tmp0_);
	state = (gint) ((_tmp1_ - 1) % ROTATION_PLUGIN_STATE_COUNT);
	_tmp2_ = self->priv->bvw;
	bacon_video_widget_set_rotation (_tmp2_, (BvwRotation) state);
	rotation_plugin_store_state (self, NULL, NULL);
}


static void rotation_plugin_cb_rotate_right (RotationPlugin* self) {
	gint state = 0;
	BaconVideoWidget* _tmp0_ = NULL;
	BvwRotation _tmp1_ = 0;
	BaconVideoWidget* _tmp2_ = NULL;
	g_return_if_fail (self != NULL);
	_tmp0_ = self->priv->bvw;
	_tmp1_ = bacon_video_widget_get_rotation (_tmp0_);
	state = (gint) ((_tmp1_ + 1) % ROTATION_PLUGIN_STATE_COUNT);
	_tmp2_ = self->priv->bvw;
	bacon_video_widget_set_rotation (_tmp2_, (BvwRotation) state);
	rotation_plugin_store_state (self, NULL, NULL);
}


static void rotation_plugin_cb_file_closed (RotationPlugin* self) {
	BaconVideoWidget* _tmp0_ = NULL;
	GtkActionGroup* _tmp1_ = NULL;
	g_return_if_fail (self != NULL);
	_tmp0_ = self->priv->bvw;
	bacon_video_widget_set_rotation (_tmp0_, BVW_ROTATION_R_ZERO);
	_tmp1_ = self->priv->action_group;
	gtk_action_group_set_sensitive (_tmp1_, FALSE);
}


static void rotation_plugin_cb_file_opened (RotationPlugin* self, const gchar* mrl) {
	GtkActionGroup* _tmp0_ = NULL;
	const gchar* _tmp1_ = NULL;
	g_return_if_fail (self != NULL);
	g_return_if_fail (mrl != NULL);
	_tmp0_ = self->priv->action_group;
	gtk_action_group_set_sensitive (_tmp0_, TRUE);
	_tmp1_ = mrl;
	rotation_plugin_try_restore_state (self, _tmp1_, NULL, NULL);
}


static void rotation_plugin_store_state_data_free (gpointer _data) {
	RotationPluginStoreStateData* _data_;
	_data_ = _data;
	_g_object_unref0 (_data_->self);
	g_slice_free (RotationPluginStoreStateData, _data_);
}


static gpointer _g_object_ref0 (gpointer self) {
	return self ? g_object_ref (self) : NULL;
}


static void rotation_plugin_store_state (RotationPlugin* self, GAsyncReadyCallback _callback_, gpointer _user_data_) {
	RotationPluginStoreStateData* _data_;
	RotationPlugin* _tmp0_ = NULL;
	_data_ = g_slice_new0 (RotationPluginStoreStateData);
	_data_->_async_result = g_simple_async_result_new (G_OBJECT (self), _callback_, _user_data_, rotation_plugin_store_state);
	g_simple_async_result_set_op_res_gpointer (_data_->_async_result, _data_, rotation_plugin_store_state_data_free);
	_tmp0_ = _g_object_ref0 (self);
	_data_->self = _tmp0_;
	rotation_plugin_store_state_co (_data_);
}


static void rotation_plugin_store_state_finish (RotationPlugin* self, GAsyncResult* _res_) {
	RotationPluginStoreStateData* _data_;
	_data_ = g_simple_async_result_get_op_res_gpointer (G_SIMPLE_ASYNC_RESULT (_res_));
}


static void rotation_plugin_store_state_ready (GObject* source_object, GAsyncResult* _res_, gpointer _user_data_) {
	RotationPluginStoreStateData* _data_;
	_data_ = _user_data_;
	_data_->_source_object_ = source_object;
	_data_->_res_ = _res_;
	rotation_plugin_store_state_co (_data_);
}


static gboolean rotation_plugin_store_state_co (RotationPluginStoreStateData* _data_) {
	switch (_data_->_state_) {
		case 0:
		goto _state_0;
		case 1:
		goto _state_1;
		case 2:
		goto _state_2;
		default:
		g_assert_not_reached ();
	}
	_state_0:
	_data_->_tmp0_ = NULL;
	g_object_get ((PeasActivatable*) _data_->self, "object", &_data_->_tmp0_, NULL);
	_data_->_tmp1_ = NULL;
	_data_->_tmp1_ = _data_->_tmp0_;
	_data_->t = G_TYPE_CHECK_INSTANCE_CAST (_data_->_tmp1_, totem_object_get_type (), TotemObject);
	_data_->_tmp2_ = NULL;
	_data_->_tmp2_ = _data_->t;
	_data_->_tmp3_ = NULL;
	_data_->_tmp3_ = totem_object_get_current_mrl (_data_->_tmp2_);
	_data_->mrl = _data_->_tmp3_;
	_data_->_tmp4_ = NULL;
	_data_->_tmp4_ = _data_->mrl;
	if (_data_->_tmp4_ == NULL) {
		_g_free0 (_data_->mrl);
		_g_object_unref0 (_data_->t);
		if (_data_->_state_ == 0) {
			g_simple_async_result_complete_in_idle (_data_->_async_result);
		} else {
			g_simple_async_result_complete (_data_->_async_result);
		}
		g_object_unref (_data_->_async_result);
		return FALSE;
	}
	_data_->_tmp5_ = NULL;
	_data_->_tmp5_ = _data_->mrl;
	_data_->_tmp6_ = NULL;
	_data_->_tmp6_ = g_file_new_for_uri (_data_->_tmp5_);
	_data_->file = _data_->_tmp6_;
	{
		_data_->_tmp7_ = NULL;
		_data_->_tmp7_ = _data_->file;
		_data_->_state_ = 1;
		g_file_query_info_async (_data_->_tmp7_, GIO_ROTATION_FILE_ATTRIBUTE, G_FILE_QUERY_INFO_NONE, G_PRIORITY_DEFAULT, NULL, rotation_plugin_store_state_ready, _data_);
		return FALSE;
		_state_1:
		_data_->_tmp8_ = NULL;
		_data_->_tmp8_ = g_file_query_info_finish (_data_->_tmp7_, _data_->_res_, &_data_->_inner_error_);
		_data_->file_info = _data_->_tmp8_;
		if (_data_->_inner_error_ != NULL) {
			goto __catch0_g_error;
		}
		_data_->_tmp9_ = NULL;
		_data_->_tmp9_ = g_strdup ("");
		_data_->state_str = _data_->_tmp9_;
		_data_->_tmp10_ = NULL;
		_data_->_tmp10_ = _data_->self->priv->bvw;
		_data_->_tmp11_ = 0;
		_data_->_tmp11_ = bacon_video_widget_get_rotation (_data_->_tmp10_);
		_data_->rotation = _data_->_tmp11_;
		_data_->_tmp12_ = 0;
		_data_->_tmp12_ = _data_->rotation;
		if (_data_->_tmp12_ != BVW_ROTATION_R_ZERO) {
			_data_->_tmp13_ = 0;
			_data_->_tmp13_ = _data_->rotation;
			_data_->_tmp14_ = NULL;
			_data_->_tmp14_ = g_strdup_printf ("%u", (guint) _data_->_tmp13_);
			_g_free0 (_data_->state_str);
			_data_->state_str = _data_->_tmp14_;
		}
		_data_->_tmp15_ = NULL;
		_data_->_tmp15_ = _data_->file_info;
		_data_->_tmp16_ = NULL;
		_data_->_tmp16_ = _data_->state_str;
		g_file_info_set_attribute_string (_data_->_tmp15_, GIO_ROTATION_FILE_ATTRIBUTE, _data_->_tmp16_);
		_data_->_tmp17_ = NULL;
		_data_->_tmp17_ = _data_->file;
		_data_->_tmp18_ = NULL;
		_data_->_tmp18_ = _data_->file_info;
		_data_->_state_ = 2;
		g_file_set_attributes_async (_data_->_tmp17_, _data_->_tmp18_, G_FILE_QUERY_INFO_NONE, G_PRIORITY_DEFAULT, NULL, rotation_plugin_store_state_ready, _data_);
		return FALSE;
		_state_2:
		g_file_set_attributes_finish (_data_->_tmp17_, _data_->_res_, NULL, &_data_->_inner_error_);
		if (_data_->_inner_error_ != NULL) {
			_g_free0 (_data_->state_str);
			_g_object_unref0 (_data_->file_info);
			goto __catch0_g_error;
		}
		_g_free0 (_data_->state_str);
		_g_object_unref0 (_data_->file_info);
	}
	goto __finally0;
	__catch0_g_error:
	{
		_data_->e = _data_->_inner_error_;
		_data_->_inner_error_ = NULL;
		_data_->_tmp19_ = NULL;
		_data_->_tmp19_ = _data_->e;
		_data_->_tmp20_ = NULL;
		_data_->_tmp20_ = _data_->_tmp19_->message;
		g_warning ("totem-rotation-plugin.vala:145: Could not store file attribute: %s", _data_->_tmp20_);
		_g_error_free0 (_data_->e);
	}
	__finally0:
	if (_data_->_inner_error_ != NULL) {
		_g_object_unref0 (_data_->file);
		_g_free0 (_data_->mrl);
		_g_object_unref0 (_data_->t);
		g_critical ("file %s: line %d: uncaught error: %s (%s, %d)", __FILE__, __LINE__, _data_->_inner_error_->message, g_quark_to_string (_data_->_inner_error_->domain), _data_->_inner_error_->code);
		g_clear_error (&_data_->_inner_error_);
		return FALSE;
	}
	_g_object_unref0 (_data_->file);
	_g_free0 (_data_->mrl);
	_g_object_unref0 (_data_->t);
	if (_data_->_state_ == 0) {
		g_simple_async_result_complete_in_idle (_data_->_async_result);
	} else {
		g_simple_async_result_complete (_data_->_async_result);
	}
	g_object_unref (_data_->_async_result);
	return FALSE;
}


static void rotation_plugin_try_restore_state_data_free (gpointer _data) {
	RotationPluginTryRestoreStateData* _data_;
	_data_ = _data;
	_g_free0 (_data_->mrl);
	_g_object_unref0 (_data_->self);
	g_slice_free (RotationPluginTryRestoreStateData, _data_);
}


static void rotation_plugin_try_restore_state (RotationPlugin* self, const gchar* mrl, GAsyncReadyCallback _callback_, gpointer _user_data_) {
	RotationPluginTryRestoreStateData* _data_;
	RotationPlugin* _tmp0_ = NULL;
	const gchar* _tmp1_ = NULL;
	gchar* _tmp2_ = NULL;
	_data_ = g_slice_new0 (RotationPluginTryRestoreStateData);
	_data_->_async_result = g_simple_async_result_new (G_OBJECT (self), _callback_, _user_data_, rotation_plugin_try_restore_state);
	g_simple_async_result_set_op_res_gpointer (_data_->_async_result, _data_, rotation_plugin_try_restore_state_data_free);
	_tmp0_ = _g_object_ref0 (self);
	_data_->self = _tmp0_;
	_tmp1_ = mrl;
	_tmp2_ = g_strdup (_tmp1_);
	_g_free0 (_data_->mrl);
	_data_->mrl = _tmp2_;
	rotation_plugin_try_restore_state_co (_data_);
}


static void rotation_plugin_try_restore_state_finish (RotationPlugin* self, GAsyncResult* _res_) {
	RotationPluginTryRestoreStateData* _data_;
	_data_ = g_simple_async_result_get_op_res_gpointer (G_SIMPLE_ASYNC_RESULT (_res_));
}


static void rotation_plugin_try_restore_state_ready (GObject* source_object, GAsyncResult* _res_, gpointer _user_data_) {
	RotationPluginTryRestoreStateData* _data_;
	_data_ = _user_data_;
	_data_->_source_object_ = source_object;
	_data_->_res_ = _res_;
	rotation_plugin_try_restore_state_co (_data_);
}


static guint64 uint64_parse (const gchar* str) {
	guint64 result = 0ULL;
	const gchar* _tmp0_ = NULL;
	guint64 _tmp1_ = 0ULL;
	g_return_val_if_fail (str != NULL, 0ULL);
	_tmp0_ = str;
	_tmp1_ = g_ascii_strtoull (_tmp0_, NULL, (guint) 0);
	result = _tmp1_;
	return result;
}


static gboolean rotation_plugin_try_restore_state_co (RotationPluginTryRestoreStateData* _data_) {
	switch (_data_->_state_) {
		case 0:
		goto _state_0;
		case 1:
		goto _state_1;
		default:
		g_assert_not_reached ();
	}
	_state_0:
	_data_->_tmp0_ = NULL;
	_data_->_tmp0_ = _data_->mrl;
	_data_->_tmp1_ = NULL;
	_data_->_tmp1_ = g_file_new_for_uri (_data_->_tmp0_);
	_data_->file = _data_->_tmp1_;
	_data_->_tmp3_ = NULL;
	_data_->_tmp3_ = _data_->file;
	_data_->_tmp4_ = FALSE;
	_data_->_tmp4_ = g_file_has_uri_scheme (_data_->_tmp3_, "http");
	if (_data_->_tmp4_) {
		_data_->_tmp2_ = TRUE;
	} else {
		_data_->_tmp5_ = NULL;
		_data_->_tmp5_ = _data_->file;
		_data_->_tmp6_ = FALSE;
		_data_->_tmp6_ = g_file_has_uri_scheme (_data_->_tmp5_, "dvd");
		_data_->_tmp2_ = _data_->_tmp6_;
	}
	_data_->_tmp7_ = FALSE;
	_data_->_tmp7_ = _data_->_tmp2_;
	if (_data_->_tmp7_) {
		_g_object_unref0 (_data_->file);
		if (_data_->_state_ == 0) {
			g_simple_async_result_complete_in_idle (_data_->_async_result);
		} else {
			g_simple_async_result_complete (_data_->_async_result);
		}
		g_object_unref (_data_->_async_result);
		return FALSE;
	}
	{
		_data_->_tmp8_ = NULL;
		_data_->_tmp8_ = _data_->file;
		_data_->_state_ = 1;
		g_file_query_info_async (_data_->_tmp8_, GIO_ROTATION_FILE_ATTRIBUTE, G_FILE_QUERY_INFO_NONE, G_PRIORITY_DEFAULT, NULL, rotation_plugin_try_restore_state_ready, _data_);
		return FALSE;
		_state_1:
		_data_->_tmp9_ = NULL;
		_data_->_tmp9_ = g_file_query_info_finish (_data_->_tmp8_, _data_->_res_, &_data_->_inner_error_);
		_data_->file_info = _data_->_tmp9_;
		if (_data_->_inner_error_ != NULL) {
			goto __catch1_g_error;
		}
		_data_->_tmp10_ = NULL;
		_data_->_tmp10_ = _data_->file_info;
		_data_->_tmp11_ = NULL;
		_data_->_tmp11_ = g_file_info_get_attribute_string (_data_->_tmp10_, GIO_ROTATION_FILE_ATTRIBUTE);
		_data_->_tmp12_ = NULL;
		_data_->_tmp12_ = g_strdup (_data_->_tmp11_);
		_data_->state_str = _data_->_tmp12_;
		_data_->_tmp13_ = NULL;
		_data_->_tmp13_ = _data_->state_str;
		if (_data_->_tmp13_ != NULL) {
			_data_->_tmp14_ = NULL;
			_data_->_tmp14_ = _data_->state_str;
			_data_->_tmp15_ = 0ULL;
			_data_->_tmp15_ = uint64_parse (_data_->_tmp14_);
			_data_->state = (gint) ((BvwRotation) _data_->_tmp15_);
			_data_->_tmp16_ = NULL;
			_data_->_tmp16_ = _data_->self->priv->bvw;
			_data_->_tmp17_ = 0;
			_data_->_tmp17_ = _data_->state;
			bacon_video_widget_set_rotation (_data_->_tmp16_, (BvwRotation) _data_->_tmp17_);
		}
		_g_free0 (_data_->state_str);
		_g_object_unref0 (_data_->file_info);
	}
	goto __finally1;
	__catch1_g_error:
	{
		_data_->e = _data_->_inner_error_;
		_data_->_inner_error_ = NULL;
		_data_->_tmp18_ = NULL;
		_data_->_tmp18_ = _data_->e;
		_data_->_tmp19_ = NULL;
		_data_->_tmp19_ = _data_->_tmp18_->message;
		g_warning ("totem-rotation-plugin.vala:163: Could not query file attribute: %s", _data_->_tmp19_);
		_g_error_free0 (_data_->e);
	}
	__finally1:
	if (_data_->_inner_error_ != NULL) {
		_g_object_unref0 (_data_->file);
		g_critical ("file %s: line %d: uncaught error: %s (%s, %d)", __FILE__, __LINE__, _data_->_inner_error_->message, g_quark_to_string (_data_->_inner_error_->domain), _data_->_inner_error_->code);
		g_clear_error (&_data_->_inner_error_);
		return FALSE;
	}
	_g_object_unref0 (_data_->file);
	if (_data_->_state_ == 0) {
		g_simple_async_result_complete_in_idle (_data_->_async_result);
	} else {
		g_simple_async_result_complete (_data_->_async_result);
	}
	g_object_unref (_data_->_async_result);
	return FALSE;
}


RotationPlugin* rotation_plugin_construct (GType object_type) {
	RotationPlugin * self = NULL;
	self = (RotationPlugin*) g_object_new (object_type, NULL);
	return self;
}


RotationPlugin* rotation_plugin_new (void) {
	return rotation_plugin_construct (TYPE_ROTATION_PLUGIN);
}


static GObject* rotation_plugin_real_get_object (PeasActivatable* base) {
	GObject* result;
	RotationPlugin* self;
	GObject* _tmp0_ = NULL;
	GObject* _tmp1_ = NULL;
	self = (RotationPlugin*) base;
	_tmp0_ = self->priv->_object;
	_tmp1_ = _g_object_ref0 (_tmp0_);
	result = _tmp1_;
	return result;
}


static void rotation_plugin_real_set_object (PeasActivatable* base, GObject* value) {
	RotationPlugin* self;
	GObject* _tmp0_ = NULL;
	GObject* _tmp1_ = NULL;
	self = (RotationPlugin*) base;
	_tmp0_ = value;
	_tmp1_ = _g_object_ref0 (_tmp0_);
	_g_object_unref0 (self->priv->_object);
	self->priv->_object = _tmp1_;
	g_object_notify ((GObject *) self, "object");
}


static void rotation_plugin_class_init (RotationPluginClass * klass) {
	rotation_plugin_parent_class = g_type_class_peek_parent (klass);
	g_type_class_add_private (klass, sizeof (RotationPluginPrivate));
	G_OBJECT_CLASS (klass)->get_property = _vala_rotation_plugin_get_property;
	G_OBJECT_CLASS (klass)->set_property = _vala_rotation_plugin_set_property;
	G_OBJECT_CLASS (klass)->finalize = rotation_plugin_finalize;
	g_object_class_install_property (G_OBJECT_CLASS (klass), ROTATION_PLUGIN_OBJECT, g_param_spec_object ("object", "object", "object", G_TYPE_OBJECT, G_PARAM_STATIC_NAME | G_PARAM_STATIC_NICK | G_PARAM_STATIC_BLURB | G_PARAM_READABLE | G_PARAM_WRITABLE | G_PARAM_CONSTRUCT_ONLY));
}


static void rotation_plugin_peas_activatable_interface_init (PeasActivatableInterface * iface) {
	rotation_plugin_peas_activatable_parent_iface = g_type_interface_peek_parent (iface);
	iface->activate = (void (*)(PeasActivatable*)) rotation_plugin_real_activate;
	iface->deactivate = (void (*)(PeasActivatable*)) rotation_plugin_real_deactivate;
	iface->update_state = (void (*)(PeasActivatable*)) rotation_plugin_real_update_state;
}


static void rotation_plugin_instance_init (RotationPlugin * self) {
	self->priv = ROTATION_PLUGIN_GET_PRIVATE (self);
	self->priv->bvw = NULL;
}


static void rotation_plugin_finalize (GObject* obj) {
	RotationPlugin * self;
	self = G_TYPE_CHECK_INSTANCE_CAST (obj, TYPE_ROTATION_PLUGIN, RotationPlugin);
	_g_object_unref0 (self->priv->_object);
	_g_object_unref0 (self->priv->bvw);
	_g_object_unref0 (self->priv->action_group);
	G_OBJECT_CLASS (rotation_plugin_parent_class)->finalize (obj);
}


GType rotation_plugin_get_type (void) {
	return rotation_plugin_type_id;
}


GType rotation_plugin_register_type (GTypeModule * module) {
	static const GTypeInfo g_define_type_info = { sizeof (RotationPluginClass), (GBaseInitFunc) NULL, (GBaseFinalizeFunc) NULL, (GClassInitFunc) rotation_plugin_class_init, (GClassFinalizeFunc) NULL, NULL, sizeof (RotationPlugin), 0, (GInstanceInitFunc) rotation_plugin_instance_init, NULL };
	static const GInterfaceInfo peas_activatable_info = { (GInterfaceInitFunc) rotation_plugin_peas_activatable_interface_init, (GInterfaceFinalizeFunc) NULL, NULL};
	rotation_plugin_type_id = g_type_module_register_type (module, G_TYPE_OBJECT, "RotationPlugin", &g_define_type_info, 0);
	g_type_module_add_interface (module, rotation_plugin_type_id, peas_activatable_get_type (), &peas_activatable_info);
	return rotation_plugin_type_id;
}


static void _vala_rotation_plugin_get_property (GObject * object, guint property_id, GValue * value, GParamSpec * pspec) {
	RotationPlugin * self;
	self = G_TYPE_CHECK_INSTANCE_CAST (object, TYPE_ROTATION_PLUGIN, RotationPlugin);
	switch (property_id) {
		case ROTATION_PLUGIN_OBJECT:
		g_value_take_object (value, rotation_plugin_real_get_object ((PeasActivatable*) self));
		break;
		default:
		G_OBJECT_WARN_INVALID_PROPERTY_ID (object, property_id, pspec);
		break;
	}
}


static void _vala_rotation_plugin_set_property (GObject * object, guint property_id, const GValue * value, GParamSpec * pspec) {
	RotationPlugin * self;
	self = G_TYPE_CHECK_INSTANCE_CAST (object, TYPE_ROTATION_PLUGIN, RotationPlugin);
	switch (property_id) {
		case ROTATION_PLUGIN_OBJECT:
		rotation_plugin_real_set_object ((PeasActivatable*) self, g_value_get_object (value));
		break;
		default:
		G_OBJECT_WARN_INVALID_PROPERTY_ID (object, property_id, pspec);
		break;
	}
}


void peas_register_types (GTypeModule* module) {
	PeasObjectModule* objmodule = NULL;
	GTypeModule* _tmp0_ = NULL;
	PeasObjectModule* _tmp1_ = NULL;
	g_return_if_fail (module != NULL);
	rotation_plugin_register_type (module);
	_tmp0_ = module;
	_tmp1_ = _g_object_ref0 (G_TYPE_CHECK_INSTANCE_TYPE (_tmp0_, peas_object_module_get_type ()) ? ((PeasObjectModule*) _tmp0_) : NULL);
	objmodule = _tmp1_;
	peas_object_module_register_extension_type (objmodule, peas_activatable_get_type (), TYPE_ROTATION_PLUGIN);
	_g_object_unref0 (objmodule);
}


