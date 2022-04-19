class Solution {
public:
    TreeNode*prev,*first,*second;
   
    void inorder(TreeNode*root){
        if(root==NULL){
            return;
        }
        inorder(root->left);
        if(!first&& root->val < prev->val){
            first=prev;
        }
        if(first && root->val<prev->val){
            second=root;
        }
        prev=root;
        inorder(root->right);
        
    }
    
    void recoverTree(TreeNode* root) {
        prev=new TreeNode(INT_MIN);
        inorder(root);
        swap(first->val,second->val);
    }
};