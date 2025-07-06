class Solution {
public:
    vector<int>final;
    void preorder(TreeNode* root){
        if(root == NULL){
            return;
        }
        final.push_back(root->val);
        preorderTraversal(root->left);
        preorderTraversal(root->right);
    }
    vector<int> preorderTraversal(TreeNode* root) {
        preorder(root);
        return final;
    }
}