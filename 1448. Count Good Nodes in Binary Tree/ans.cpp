#include <bits/stdc++.h>
using namespace std;
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
class Solution
{
public:
    int ans = 0;
    int goodNodes(TreeNode *root, int pmax = INT_MIN)
    {
        if (root == NULL)
            return 0;
        int cmax = pmax;
        if ((root->val) >= pmax)
        {
            cmax = root->val;
            ans++;
        }
        goodNodes(root->left, cmax);
        goodNodes(root->right, cmax);
        return ans;
    }
};