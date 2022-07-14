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

/*
Runtime: 46 ms, faster than 38.22% of C++ online submissions for Construct Binary Tree from Preorder and Inorder Traversal.
Memory Usage: 26.4 MB, less than 28.28% of C++ online submissions for Construct Binary Tree from Preorder and Inorder Traversal.

*/
class Solution
{
public:
    TreeNode *bfs(vector<int> &preorder, int preStart, int preEnd, vector<int> &inorder, int inStart, int inEnd)
    {
        if (preStart > preEnd || inStart > inEnd)
        {
            return NULL;
        }
        int rootVal = preorder[preStart];
        TreeNode *root = new TreeNode(rootVal);
        int k = 0;
        for (int i = inStart; i <= inEnd; i++)
        {
            if (rootVal == inorder[i])
            {
                k = i;
                break;
            }
        }
        root->left = bfs(preorder, preStart + 1, preStart + (k - inStart), inorder, inStart, k - 1);
        root->right = bfs(preorder, preStart + (k - inStart) + 1, preEnd, inorder, k + 1, inEnd);
        return root;
    }
    TreeNode *buildTree(vector<int> &preorder, vector<int> &inorder)
    {
        unordered_map<int, int> mpp;
        for (int i = 0; i < inorder.size(); ++i)
            mpp[inorder[i]] = i;

        return bfs(preorder, 0, preorder.size() - 1, inorder, 0, inorder.size() - 1);
    }
};