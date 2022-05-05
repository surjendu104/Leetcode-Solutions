class Solution
{
public:
    bool isValidBST(TreeNode *root)
    {
        if (root == nullptr)
            return true;
        if (!isValidBST(root->left))
            return false;
        if (prev_val >= root->val && !is_first)
            return false;
        prev_val = root->val;
        is_first = false;
        return isValidBST(root->right);
    }

private:
    int prev_val = INT_MIN;
    bool is_first = true;
};