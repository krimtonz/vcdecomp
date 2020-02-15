
#include <stdlib.h>
#include "tree.h"
#include "gClassCPU.h"

bool treeInit(gClassCPU_t *cpu, uint32_t code_end)

{
  func_tree_t *tree;
  
  tree = cpu->func_tree;
  if (tree == NULL) {
    return false;
  }
  tree->node_cnt = 0;
  tree->f_size = 0;
  tree->code_end = code_end;
  tree->n64_start = 0;
  tree->n64_end = 0x80000000;
  tree->code_tree_root = NULL;
  tree->other_tree_root = NULL;
  tree->new_f_cnt = 0;
  tree->unk_0x74 = 0;
  tree->tree_to_clean = 0;
  tree->node_being_cleaned = NULL;
  tree->node_cleaned_found = 0;
  return true;
}

