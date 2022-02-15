class Solution {
 public:
  bool isValidBST(TreeNode *root) {
    return helper(root, LLONG_MIN, LLONG_MAX);
  }

 private:
  bool helper(TreeNode *root, long long lowerBound, long long upperBound) {
    if (!root) {
      return true;
    }
    if (root->val <= lowerBound || root->val >= upperBound) {
      return false;
    }
    return helper(root->left, lowerBound, root->val) && helper(root->right, root->val, upperBound);
  }
};
