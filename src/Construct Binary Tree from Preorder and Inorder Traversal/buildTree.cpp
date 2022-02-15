class Solution {
 public:
  TreeNode *buildTree(vector<int> &preorder, vector<int> &inorder) {
    for (int i = 0; i < inorder.size(); ++i) {
      inorderIndexMap[inorder[i]] = i;
    }
    return vectorToTree(preorder, 0, (int)preorder.size() - 1);
  }

 private:
  int p = 0;
  unordered_map<int, int> inorderIndexMap;  // value to index map
  TreeNode *vectorToTree(const vector<int> &preorder, int left, int right) {
    if (left > right) return nullptr; // range empty
    auto *root = new TreeNode(preorder[p]);
    ++p;
    root->left = vectorToTree(preorder, left, inorderIndexMap[root->val] - 1);
    root->right = vectorToTree(preorder, inorderIndexMap[root->val] + 1, right);
    return root;
  }
};
