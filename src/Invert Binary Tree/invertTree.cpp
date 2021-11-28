

struct TreeNode {
  int val;
  TreeNode *left;
  TreeNode *right;
  TreeNode() : val(0), left(nullptr), right(nullptr) {
  }
  TreeNode(int x) : val(x), left(nullptr), right(nullptr) {
  }
  TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {
  }
};

class Solution {
 public:
  TreeNode *invertTree(TreeNode *root) {
    swapLR(root);
    return root;
  }

 private:
  void swapLR(TreeNode *root) {
    if (!root) {
      return;
    }

    swapLR(root->left);
    swapLR(root->right);
    TreeNode *tmp;
    tmp = root->left;
    root->left = root->right;
    root->right = tmp;
  }
};
