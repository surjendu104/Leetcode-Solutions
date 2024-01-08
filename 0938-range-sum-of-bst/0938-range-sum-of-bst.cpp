/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    int rangeSumBST(TreeNode* root, int low, int high) {
        function<void(TreeNode*, int, int, vector<int>&)> helper = [&](TreeNode* node, int low, int high, vector<int> &arr) -> void {
            if(node == NULL) return;
            if(node->val <= high && node->val >= low) arr.push_back(node->val);
            helper(node->left, low, high, arr);
            helper(node->right, low, high, arr);
        };
        vector<int> nodes;
        helper(root, low, high, nodes);
        int ans = accumulate(begin(nodes), end(nodes), 0);
        return ans;
    }
};