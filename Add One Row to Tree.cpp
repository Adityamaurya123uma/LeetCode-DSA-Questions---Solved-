
class Solution
{
public:
    TreeNode *addOneRow(TreeNode *root, int val, int depth)
    {
        // edge case, if append new row at root
        if (depth == 1)
        {
            TreeNode *newnode = new TreeNode(val);
            newnode->left = root;
            return newnode;
        }

        // find the required row needed to append new row
        // level-order traversal
        queue<TreeNode *> queue;
        queue.push(root);
        while (!queue.empty())
        {
            depth--;
            if (depth == 1)
                break; // finded the row
            int len = queue.size();
            for (int i = 0; i < len; i++)
            {
                TreeNode *currnode = queue.front();
                queue.pop();
                if (currnode->left != NULL)
                    queue.push(currnode->left);
                if (currnode->right != NULL)
                    queue.push(currnode->right);
            }
        }

        // append rows below required depth of tree
        while (!queue.empty())
        {
            TreeNode *currnode = queue.front();
            queue.pop();
            TreeNode *leftnode = new TreeNode(val);
            TreeNode *rightnode = new TreeNode(val);
            leftnode->left = currnode->left;
            rightnode->right = currnode->right;
            currnode->left = leftnode;
            currnode->right = rightnode;
        }
        return root;
    }
};