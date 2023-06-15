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
    int maxLevelSum(TreeNode* root) {
        if(root == NULL)return 0;
        int sum = INT_MIN, ans = 1, levelcount = 0;
        queue<TreeNode*> q;
        q.push(root);
        
        while(q.size()) {
            int n = q.size();
            int levelsum = 0;
            for(int i = 0; i < n; ++i) {
                TreeNode* node = q.front();
                q.pop();
                if(node->left)q.push(node->left);
                if(node->right)q.push(node->right);
                levelsum+=node->val;
            }
            levelcount++;
            if(levelsum>sum) {
                sum = levelsum;
                ans = levelcount;
                // cout<<"dbg : "<<sum<<' '<<levelcount<<endl;
            }
            
        }
        // cout<<"dbg : "<<sum<<' '<<levelcount<<endl;
        return ans;
    }
};