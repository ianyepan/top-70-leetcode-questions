class Solution {
 public:
  // BFS approach using queue
  vector<vector<int>> levelOrder(TreeNode *root) {
    if (!root) {
      return {};
    }
    vector<vector<int>> ans;
    queue<TreeNode *> q;
    q.push(root);
    while (!q.empty()) {
      int size = q.size();
      vector<int> currLevel;
      while (size--) {
        auto node = q.front();
        q.pop();
        currLevel.push_back(node->val);
        if (node->left) {
          q.push(node->left);
        }
        if (node->right) {
          q.push(node->right);
        }
      }
      ans.push_back(currLevel);
    }
    return ans;
  }
};
