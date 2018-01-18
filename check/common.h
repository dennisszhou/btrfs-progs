/*
 * This program is free software; you can redistribute it and/or
 * modify it under the terms of the GNU General Public
 * License v2 as published by the Free Software Foundation.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
 * General Public License for more details.
 *
 * You should have received a copy of the GNU General Public
 * License along with this program; if not, write to the
 * Free Software Foundation, Inc., 59 Temple Place - Suite 330,
 * Boston, MA 021110-1307, USA.
 */

/*
 * Defines and function declarations for code shared by both lowmem and
 * original mode
 */
#ifndef __BTRFS_CHECK_COMMON_H__
#define __BTRFS_CHECK_COMMON_H__
#include "ctree.h"

/*
 * Use for tree walk to walk through trees whose leaves/nodes can be shared
 * between different trees. (Namely subvolume/fs trees)
 */
struct node_refs {
	u64 bytenr[BTRFS_MAX_LEVEL];
	u64 refs[BTRFS_MAX_LEVEL];
	int need_check[BTRFS_MAX_LEVEL];
	/* field for checking all trees */
	int checked[BTRFS_MAX_LEVEL];
	/* the corresponding extent should be marked as full backref or not */
	int full_backref[BTRFS_MAX_LEVEL];
};

extern u64 bytes_used;
extern u64 total_csum_bytes;
extern u64 total_btree_bytes;
extern u64 total_fs_tree_bytes;
extern u64 total_extent_tree_bytes;
extern u64 btree_space_waste;
extern u64 data_bytes_allocated;
extern u64 data_bytes_referenced;
extern struct list_head duplicate_extents;
extern struct list_head delete_items;
extern int no_holes;
extern int init_extent_tree;
extern int check_data_csum;
extern struct btrfs_fs_info *global_info;
extern struct task_ctx ctx;
extern struct cache_tree *roots_info_cache;

#endif