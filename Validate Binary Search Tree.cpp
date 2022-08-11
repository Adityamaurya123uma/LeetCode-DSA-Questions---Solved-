class Solution
{
    bool dfs(TreeNode *root, long long mn, long long mx)
    {
        if (!root)
            return true;

        if (root->val <= mn || root->val >= mx)
            return false;

        bool left = dfs(root->left, mn, root->val);
        bool right = dfs(root->right, root->val, mx);

        return left && right;
    }

public:
    bool isValidBST(TreeNode *root)
    {
        return dfs(root, LONG_MIN, LONG_MAX);
    }
};