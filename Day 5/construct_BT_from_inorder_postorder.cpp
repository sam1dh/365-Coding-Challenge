/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    int search_in_inorder(vector<int>& inorder, int element) {
        for(int i = 0; i < inorder.size(); i++) {
            if(inorder[i] == element) {
                return i;
            }
        }
        return -1;
    }

    TreeNode* constructing(vector<int>& inorder, vector<int>& postorder, int &postindex, 
                          int inorderstartindex, int inorderendindex) {
        // Base case
        if(postindex < 0 || inorderstartindex > inorderendindex) {
            return nullptr;
        }

        // Element in the postorder
        int element = postorder[postindex];
        postindex--;

        TreeNode* root = new TreeNode(element);

        // Search element in the inorder
        int position = search_in_inorder(inorder, element);

        // Right subtree first (postorder is L-R-root, so we process right before left when going backwards)
        root->right = constructing(inorder, postorder, postindex, position + 1, inorderendindex);
        root->left = constructing(inorder, postorder, postindex, inorderstartindex, position - 1);

        return root;
    }

    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        int postindex = postorder.size() - 1;
        int inorderstartindex = 0;
        int inorderendindex = inorder.size() - 1;
        TreeNode* root = constructing(inorder, postorder, postindex, inorderstartindex, inorderendindex);
        return root;
    }
};