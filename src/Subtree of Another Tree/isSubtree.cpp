class Solution {
 public:
  bool isSubtree(TreeNode *s, TreeNode *t) {  // whether t is subtree of s
    if (!t) {
      return true;
    } else if (!s) {
      return false;
    } else {
      return isSameTree(s, t) || isSubtree(s->left, t) || isSubtree(s->right, t);
    }
  }

 private:
  bool isSameTree(TreeNode *p, TreeNode *q) {
    if (!p && !q) {
      return true;
    } else if (!p || !q) {
      return false;
    } else if (p->val != q->val) {
      return false;
    } else {
      return isSameTree(p->left, q->left) && isSameTree(p->right, q->right);
    }
  }
};
