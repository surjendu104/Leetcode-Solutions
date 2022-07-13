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

/*Runtime: 0 ms, faster than 100.00% of C++ online submissions for Binary Tree Zigzag Level Order Traversal.
Memory Usage: 12.1 MB, less than 44.94% of C++ online submissions for Binary Tree Zigzag Level Order Traversal.*/
class Solution
{
public:
    vector<vector<int>> zigzagLevelOrder(TreeNode *root)
    {
        vector<vector<int>> ans;
        if (root == NULL)
            return ans;

        queue<TreeNode *> q;
        int c = 2;
        q.push(root);
        while (!q.empty())
        {
            vector<int> res;
            int n = q.size();
            for (int i = 0; i < n; ++i)
            {
                TreeNode *node = q.front();
                q.pop();

                //                 if(c%2){
                //                     if(node->left!=NULL)q.push(node->left);
                //                     if(node->right!=NULL)q.push(node->right);
                //                     res.push_back(node->val);
                //                 }
                //                 else{
                //                     if(node->right!=NULL)q.push(node->right);
                //                     if(node->left!=NULL)q.push(node->left);
                //                     res.push_back(node->val);

                //                 }

                if (node->right != NULL)
                    q.push(node->right);
                if (node->left != NULL)
                    q.push(node->left);
                res.push_back(node->val);
            }
            ans.push_back(res);
            c++;
        }
        for (int i = 0; i < ans.size(); ++i)
        {
            if (i % 2 == 0)
                reverse(ans[i].begin(), ans[i].end());
        }
        return ans;
    }
};