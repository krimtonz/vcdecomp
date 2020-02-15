
#include <stdlib.h>
#include "tree.h"
#include "gClassCPU.h"
#include "gClassSystem.h"

bool treeInsertNode(func_tree_node_t **root,int n64_start,int n64_end,func_tree_node_t **new_node)

{
  func_tree_node_t *node;
  func_tree_node_t **node_p;
  
  if (*root == NULL) {
    if(!treeInitNode(root,NULL,n64_start,n64_end)){
      return false;
    }
    *new_node = *root;
    return true;
  }
  node_p = root;
  while(*node_p){
    node = *node_p;
    if(n64_start == node->n64_start){
      return false;
    }
    if(n64_start < node->n64_start){
      node_p = &node->left_node;
    }else{
      node_p = &node->right_node;
    }
  }
  if(!treeInitNode(node_p,node,n64_start,n64_end)){
    return false;
  }
  *new_node = node;
  return true;
}

