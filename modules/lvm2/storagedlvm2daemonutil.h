/* -*- mode: C; c-file-style: "gnu"; indent-tabs-mode: nil; -*-
 *
 * Copyright (C) 2013 Marius Vollmer <marius.vollmer@redhat.com>
 *
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 2 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, write to the Free Software
 * Foundation, Inc., 51 Franklin St, Fifth Floor, Boston, MA  02110-1301  USA
 *
 */

#ifndef __STORAGED_LVM2_DAEMON_UTIL_H__
#define __STORAGED_LVM2_DAEMON_UTIL_H__

#include <src/storageddaemontypes.h>
#include "storagedlvm2types.h"

G_BEGIN_DECLS

gboolean storaged_daemon_util_lvm2_block_is_unused (StoragedBlock  *block,
                                                    GError        **error);

gboolean storaged_daemon_util_lvm2_wipe_block      (StoragedDaemon  *daemon,
                                                    StoragedBlock   *block,
                                                    GError         **error);

GPid storaged_daemon_util_lvm2_spawn_for_variant (const gchar        **argv,
                                                  const GVariantType  *type,
                                                  void (*callback) (GPid      pid,
                                                                    GVariant *result,
                                                                    GError   *error,
                                                                    gpointer  user_data),
                                                  gpointer             user_data);

gboolean storaged_daemon_util_lvm2_name_is_reserved (const gchar *name);

StoragedLinuxVolumeGroupObject * storaged_daemon_util_lvm2_find_volume_group_object (StoragedDaemon *daemon,
                                                                                     const gchar    *name);

void storaged_daemon_util_lvm2_trigger_udev (const gchar *device_file);

G_END_DECLS

#endif /* __STORAGED_LVM2_DAEMON_UTIL_H__ */
