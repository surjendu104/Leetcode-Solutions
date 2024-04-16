class Solution {
public:
    TreeNode* addOneRow(TreeNode* root, int val, int depth) {
        if (depth == 1) {
            TreeNode* newRoot = new TreeNode(val);
            newRoot->left = root;
            return newRoot;
        }

        queue<pair<TreeNode*, int>> q;
        q.push({root, 1});
        
        while (!q.empty()) {
            TreeNode* node = q.front().first;
            int level = q.front().second;
            q.pop();
            
            if (level + 1 == depth) {
                TreeNode* leftNode = new TreeNode(val);
                leftNode->left = node->left;
                node->left = leftNode;
                
                TreeNode* rightNode = new TreeNode(val);
                rightNode->right = node->right;
                node->right = rightNode;
            } else {
                if (node->left) q.push({node->left, level + 1});
                if (node->right) q.push({node->right, level + 1});
            }
        }
        return root;
    }
};
