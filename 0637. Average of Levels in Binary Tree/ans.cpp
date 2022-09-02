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
    vector<double> averageOfLevels(TreeNode* root) {
        queue<TreeNode*>q;
        vector<double>ans;
        
        q.push(root);
        
        while(q.size()){
            double sum=0,avg=0;
            int n=q.size();
            
            
            for(int i=0;i<n;i++){
                TreeNode *temp=q.front();
                q.pop();
                sum+= (temp->val);
                
                if(temp->left)q.push(temp->left);
                if(temp->right)q.push(temp->right);
            }
            avg=sum/n;
            ans.push_back(avg);
            
            
        }
        return ans;
    }
};