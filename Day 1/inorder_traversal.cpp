class Solution {
public:
    vector<int>final;
    void inorder(TreeNode* root)
    {
        if(root == NULL){
            return;
        }
        inorderTraversal(root->left);
        final.push_back(root->val);
        inorderTraversal(root->right);
    }
    vector<int> inorderTraversal(TreeNode* root) {
        inorder(root);
        return final;
    }
};