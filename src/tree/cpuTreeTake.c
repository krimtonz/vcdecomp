#include <stdlib.h>
#include "tree.h"
#include "gClassCPU.h"
#include "gClassSystem.h"

bool cpuTreeTake(func_tree_node_t **tree_root,uint32_t *node_pos,size_t size)

{
  bool ret;
  uint32_t *f_status;
  int idx;
  int k;
  uint32_t i;
  int j;
  
  ret = false;
  idx = 0;
  j = 0x7d;
  f_status = gSystem->cpu->func_status;
  do {
    if (*f_status != 0xffffffff) {
      i = 1;
      k = 0x20;
      do {
        if ((*f_status & i) == 0) {
          ret = true;
          *f_status = *f_status | i;
          *node_pos = idx + (0x20 - k) | 0x10000;
          break;
        }
        k = k + -1;
        i = i << 1;
      } while (k != 0);
    }
    if (ret) break;
    f_status = f_status + 1;
    idx = idx + 0x20;
    j = j + -1;
  } while (j != 0);
  if (!ret) {
    *node_pos = 0xffffffff;
    return false;
  }
  *tree_root = gSystem->cpu->func_start + (*node_pos & 0xffff);
  return true;
}

