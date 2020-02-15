
bool treeInsertNode(func_tree_node_t **root,int n64_start,int n64_end,func_tree_node_t **new_node)

{
  bool fret;
  bool ret;
  func_tree_node_t *node;
  
  if (*root == NULL) {
    fret = treeInitNode(root,NULL,n64_start,n64_end);
    if (fret == false) {
      ret = false;
    }
    else {
      ret = true;
      *new_node = *root;
    }
  }
  else {
    do {
      node = *root;
      if (n64_start < node->n64_start) {
        root = &node->left_node;
      }
      else {
        if (n64_start <= node->n64_start) {
          return false;
        }
        root = &node->right_node;
      }
    } while (*root != NULL);
    fret = treeInitNode(root,node,n64_start,n64_end);
    if (fret == false) {
      ret = false;
    }
    else {
      ret = true;
      *new_node = *root;
    }
  }
  return ret;
}

