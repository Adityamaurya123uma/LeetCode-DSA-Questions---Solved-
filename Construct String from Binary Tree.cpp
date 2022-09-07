class Solution
{
public:
    string tree2str(TreeNode *root)
    {

        if (root == NULL)
            return "";

        string output = to_string(root->val);

        if (root->left != NULL || root->right != NULL)
            output += "(" + tree2str(root->left) + ")";
        if (root->right != NULL)
            output += "(" + tree2str(root->right) + ")";

        return output;
    }
};