class Solution {
 public:
  TreeNode *lowestCommonAncestor(TreeNode *root, TreeNode *p, TreeNode *q) {
    auto curr = root;
    while (curr) {
      if (curr->val < p->val && curr->val < q->val) {
        curr = curr->right;
      } else if (curr->val > p->val && curr->val > q->val) {
        curr = curr->left;
      } else {
        return curr;
      }
    }
    __builtin_unreachable();
  }
};
