class Solution {
    int sum=0;
public:
    TreeNode* convertBST(TreeNode* root) {
        if(root != NULL)
        {
            convertBST(root->right);
            sum+=root->val;
            root->val=sum;
            convertBST(root->left);
        }
        return root;
    }
};