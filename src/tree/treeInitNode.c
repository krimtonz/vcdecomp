
#include <stdlib.h>
#include "tree.h"
#include "gClassCPU.h"
#include "gClassSystem.h"

bool treeInitNode(func_tree_node_t **out_node,func_tree_node_t *parent,int n64_start,int n64_end)

{
  bool ret;
  uint32_t node_pos;
  func_tree_node_t *new_node;
  
  ret = cpuTreeTake(&new_node,&node_pos,0x48);
  if (ret != false) {
    new_node->n64_start = n64_start;
    new_node->n64_end = n64_end;
    new_node->addr_ref = NULL;
    new_node->ref_cnt = 0;
    new_node->unk_0x20 = 0x21;
    new_node->unk_0x00 = 0;
    new_node->code_addr = NULL;
    new_node->branch_cnt = 0;
    new_node->branches = NULL;
    new_node->checksum = 0;
    new_node->unk_0x28 = 1;
    new_node->unk_0x2c = 0;
    new_node->alloc_type = -1;
    new_node->block_pos = 0xffffffff;
    new_node->code_pos = node_pos;
    new_node->parent_node = parent;
    new_node->left_node = NULL;
    new_node->right_node = NULL;
    *out_node = new_node;
  }
  return ret != false;
}

