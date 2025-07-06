class Solution {
public:
    int height(TreeNode* root)
    {
        if(root == NULL)
        {
            return 0;
        }
        int leftheight = height(root->left);
        int rightheight = height(root->right);
        int finalans = max(leftheight,rightheight)+1;
        return finalans;
    }
    bool isBalanced(TreeNode* root) {
        if(root == NULL)
        {
            return true;
        }
        // left tree and right tree difference must be -1 
        int leftheight = height(root->left);
        int rightheight = height(root->right);
        int diff = abs(leftheight - rightheight);
        bool currnode = diff<=1;

        // this is for the checking whether the left tree or right tree is balanced or not by 
        // by checking the each node...
        bool leftans = isBalanced(root->left);
        bool rightans = isBalanced(root->right); 


        if(currnode && leftans && rightans)
        {
            return true;
        }
        else{
            return false;
        }
    }
};