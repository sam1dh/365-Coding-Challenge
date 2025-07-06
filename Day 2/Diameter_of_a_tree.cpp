class Solution {
public:
    int  height(TreeNode* root)
    {
        if(root == NULL)
        {
            return 0 ;
        }
        int lefttree = height(root->left);
        int righttree = height(root->right);
        return max(lefttree,righttree)+1;
    }
    int diameterOfBinaryTree(TreeNode* root) {
        if(root == NULL)
        {
            return 0;
        }
        int option1 = diameterOfBinaryTree(root->left);
        int option2 = diameterOfBinaryTree(root->right);
        int option3 = height(root->left) + height(root->right);
        return max(option3, max(option2,option1));
    }
};