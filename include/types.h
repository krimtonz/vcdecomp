#ifndef _TYPES_H
#define _TYPES_H

typedef struct gClassCPU    gClassCPU_t, *PgClassCPU_t;
typedef struct cpu_dev      cpu_dev_t, *Pcpu_dev_t;

typedef bool    (*load_byte_func_t)     (void *, uint32_t, uint8_t *);
typedef bool    (*load_half_func_t)     (void *, uint32_t, uint16_t *);
typedef bool    (*load_word_func_t)     (void *, uint32_t, uint32_t *);
typedef bool    (*load_double_func_t)   (void *, uint32_t, uint32_t *);
typedef bool    (*store_byte_func_t)    (void *, uint32_t, uint8_t *);
typedef bool    (*store_half_func_t)    (void *, uint32_t, uint16_t *);
typedef bool    (*store_word_func_t)    (void *, uint32_t, uint32_t *);
typedef bool    (*store_double_func_t)  (void *, uint32_t, uint32_t *);
typedef bool    (*unk_0x2C_func_t)      (void *, uint32_t, void *);

typedef struct func_tree        func_tree_t, *Pfunc_tree_t;
typedef struct cache_func       cache_func_t, *Pcache_func_t;
typedef struct func_tree_node   func_tree_node_t, *Pfunc_tree_node_t;
typedef struct branch_ent       branch_ent_t, *Pbranch_ent_t;

typedef struct gClassSystem gClassSystem_t;
#endif