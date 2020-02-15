#ifndef _CLASS_CPU
#define _CLASS_CPU

#include <stdint.h>
#include "types.h"
#include "tree.h"

struct cpu_dev {
    uint32_t                unk_0x00;       /* 0x0000 */
    void                   *cb_data;        /* 0x0004 */
    uint32_t                addr_mask;      /* 0x0008 */
    load_byte_func_t        lb;             /* 0x000C */
    load_half_func_t        lh;             /* 0x0010 */
    load_word_func_t        lw;             /* 0x0014 */
    load_double_func_t      ld;             /* 0x0018 */
    store_byte_func_t       sb;             /* 0x001C */
    store_half_func_t       sh;             /* 0x0020 */
    store_word_func_t       sw;             /* 0x0024 */
    store_double_func_t     sd;             /* 0x0028 */
    unk_0x2C_func_t         unk_0x2C;       /* 0x002C */
    uint32_t                vram_start;     /* 0x0030 */
    uint32_t                vram_end;       /* 0x0034 */
    uint32_t                pram_start;     /* 0x0038 */
    uint32_t                pram_end;       /* 0x003C */
};                                          /* 0x0040 */

struct cpu_hack {
    uint32_t    addr;              /* 0x0000 */
    uint32_t expected_inst; /* 0x0004 */
    int replacement_inst; /* 0x0008 */
}; /* 0x000C */

struct gClassCPU {
    uint32_t            status;                         /* 0x00000 */
    int                 unk_0x04;                       /* 0x00004 */
    uint64_t            lo;                             /* 0x00008 */
    uint64_t            hi;                             /* 0x00010 */
    int                 cache_cnt;                      /* 0x00018 */
    uint32_t            phys_ram_dev_idx;               /* 0x0001C */
    uint32_t            pc;                             /* 0x00020 */
    int                 unk_0x24;                       /* 0x00024 */
    char                unk_0x28[4];                    /* 0x00028 */
    func_tree_node_t   *working_node;                   /* 0x0002C */
    int                 n64_ra;                         /* 0x00030 */
    uint32_t            call_depth;                     /* 0x00034 */
    uint32_t            tick;                           /* 0x00038 */
    uint32_t            unk_0x3c;                       /* 0x0003C */
    uint32_t            unk_0x40;                       /* 0x00040 */
    char                unk_0x44[4];                    /* 0x00044 */
    uint32_t            gpr[64];                        /* 0x00048 */
    double              field_0x148;                    /* 0x00148 */
    double              fpr[32];                        /* 0x00150 */
    char                unk_0x250[0x778];               /* 0x00250 */
    uint32_t            FSCR[32];                       /* 0x009C8 */
    uint32_t            field_0xa48[64];                /* 0x00A48 */
    void               *cpuExecuteOpcode_function;      /* 0x00B48 */
    void               *cpuExecuteJump_function;        /* 0x00B4C */
    void               *cpuExecuteCall_function;        /* 0x00B50 */
    void               *cpuExecuteIdle_function;        /* 0x00B54 */
    void               *cpuExecuteLoadStore_function;   /* 0x00B58 */
    void               *cpuExecuteLoadStoreF_function;  /* 0x00B5C */
    cpu_dev_t          *devs[256];                      /* 0x00B60*/
    char                dev_idx[65536];                 /* 0x00F60 */
    void               *sm_blk_code;                    /* 0x10F60 */
    void               *lg_blk_code;                    /* 0x10F64 */
    uint32_t            sm_blk_status[192];             /* 0x10F68 */
    uint32_t            lg_blk_status[13];              /* 0x11268 */
    func_tree_node_t   *func_start;                     /* 0x1129C */
    uint32_t            func_status[125];               /* 0x112A0 */
    func_tree_t        *func_tree;                      /* 0x11494 */
    cache_func_t        blk_queue[256];                 /* 0x11498 */
    int                 hack_cnt;                       /* 0x12098 */
    struct cpu_hack     hacks[4];                       /* 0x1209C */
    char                unk_0x120cc[0x150];             /* 0x120CC */
    uint32_t            used_regs;                      /* 0x1221C */
    uint32_t            unk_0x12220;                    /* 0x12220 */
    uint32_t            unk_possible_hacks;             /* 0x12224 */ /* cpuReset sets it to 0x1, systemSetupGameALL sets it to |= 0x110 for OOT */
    char                unk_0x12228[0x4C];              /* 0x12228 */
    int                 field_0x12274;                  /* 0x12274 */
    int                 possible_mips_rd;               /* 0x12278 */
    uint32_t            possible_ppc_rd;                /* 0x1227C */
    char                unk_0x12280[0x58];              /* 0x12280 */
};

#endif