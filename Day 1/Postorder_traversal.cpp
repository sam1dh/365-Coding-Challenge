class Solution {
public:
    vector<int>final;
    void postorder(TreeNode* root){
        if(root == NULL){
            return ;
        }
        postorderTraversal(root->left);
        postorderTraversal(root->right);
        final.push_back(root->val);
    }
    vector<int> postorderTraversal(TreeNode* root) {
        postorder(root);
        return final;
    }
};