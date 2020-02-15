#ifndef _TREE_H
#define _TREE_H

#include <stdbool.h>
#include <stdlib.h>
#include <stdint.h>
#include "types.h"

struct func_tree {
    uint16_t            node_cnt;               /* 0x0000 */
    uint16_t            unk_0x02;               /* 0x0002 */
    uint32_t            f_size;                 /* 0x0004 */
    int                 code_end;               /* 0x0008 */
    uint32_t            n64_start;              /* 0x000C */
    uint32_t            n64_end;                /* 0x0010 */
    char                unk_0x14[0x20];         /* 0x0014 */
    uint32_t            unk_0x034;              /* 0x0034 */
    char                unk_0x38[0x30];         /* 0x0038 */
    func_tree_node_t   *code_tree_root;         /* 0x0068 */
    func_tree_node_t   *other_tree_root;        /* 0x006C */
    int                 new_f_cnt;              /* 0x0070 */
    uint32_t            unk_0x74;               /* 0x0074 */
    uint32_t            tree_to_clean;          /* 0x0078 */
    func_tree_node_t   *node_being_cleaned;     /* 0x007C */
    uint32_t            node_cleaned_found;     /* 0x0080 */
};                                              /* 0x0084 */

struct cache_func {
    int                 n64_addr;               /* 0x0000 */
    void               *vc_addr;                /* 0x0004 */
    func_tree_node_t   *f_blk;                  /* 0x0008 */
};                                              /* 0x000C */

struct branch_ent {
    uint32_t offset;    /* 0x0000 */
    uint32_t pc;        /* 0x0004 */
};                      /* 0x0008 */

struct func_tree_node {
    uint32_t            unk_0x00;               /* 0x0000 */
    char               *code_addr;              /* 0x0004 */
    uint32_t            branch_cnt;             /* 0x0008 */
    branch_ent_t       *branches;               /* 0x000C */
    int                 n64_start;              /* 0x0010 */
    int                 n64_end;                /* 0x0014 */
    uint32_t           *addr_ref;               /* 0x0018 */
    uint32_t            ref_cnt;                /* 0x001C */
    uint32_t            unk_0x20;               /* 0x0020 */
    uint32_t            checksum;               /* 0x0024 */
    int                 unk_0x28;               /* 0x0028 */
    uint32_t            unk_0x2c;               /* 0x002C */
    int                 alloc_type;             /* 0x0030 */
    uint32_t            block_pos;              /* 0x0034 */
    uint32_t            code_pos;               /* 0x0038 */
    func_tree_node_t   *parent_node;            /* 0x003C */
    func_tree_node_t   *left_node;              /* 0x0040 */
    func_tree_node_t   *right_node;             /* 0x0044 */
};                                              /* 0x0048 */

bool    cpuTreeTake     (func_tree_node_t **tree_root,uint32_t *node_pos,size_t size);
bool    treeInit        (gClassCPU_t *cpu, uint32_t code_end);
bool    treeInitNode    (func_tree_node_t **out_node,func_tree_node_t *parent,int n64_start,int n64_end);

#endif