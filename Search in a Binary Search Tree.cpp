class Solution {
    void dfs(TreeNode* root, int val, TreeNode*& ans) {
        if(!root) return;
    
        if(root->val == val) {
            ans = root;
        } else if(root->val > val) {
            dfs(root->left, val, ans);
        } else if(root->val < val) {
            dfs(root->right, val, ans);
        }
        
    }
public:
    TreeNode* searchBST(TreeNode* root, int val) {
        TreeNode* ans = nullptr;
        dfs(root, val, ans);
        
        return ans;
        
    }
};