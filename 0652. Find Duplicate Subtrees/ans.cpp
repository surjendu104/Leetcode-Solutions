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
    vector<TreeNode*> findDuplicateSubtrees(TreeNode* root) {
        unordered_map<string,int>mpp;
        vector<TreeNode*> res;
        traverse(mpp,res,root);
        return res;
    }
    string traverse(unordered_map<string,int> &mpp,vector<TreeNode*> &res,TreeNode* node) {
        if(node==nullptr)return "";
        
        string str = "("+traverse(mpp,res,node->left)+")"+to_string(node->val)+"("+traverse(mpp,res,node->right)+")";
        mpp[str]++;
        if(mpp[str] == 2)res.push_back(node);
        return str;
    }
};