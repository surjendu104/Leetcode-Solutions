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
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        queue<pair<TreeNode*, vector<int>>> q; // (node value, {verticals, level})
        map<int, map<int, multiset<int>>> map;

        q.push({root, {0, 0}});
        while(q.empty() == false) {
            auto v = q.front();
            q.pop();
            TreeNode* node = v.first;
            int vertical = v.second[0];
            int level = v.second[1];
            // add to map
            map[vertical][level].insert(node->val);

            if(node->left) q.push({node->left, {vertical-1, level+1}});
            if(node->right) q.push({node->right, {vertical+1, level+1}});
        }
        vector<vector<int>> v;
        for(auto it : map) {
            vector<int> col;
            for(auto q : it.second) {
                col.insert(col.end(), q.second.begin(), q.second.end());
            }
            v.push_back(col);
        }
        return v;
    }
};