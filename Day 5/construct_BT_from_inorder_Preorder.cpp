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
    int search_element_Of_preorder_in_inorder(vector<int>& inorder , int element){
        for(int i=0 ; i<inorder.size() ; i++)
        {
            if(inorder[i]==element)
            {
                return i;
            }
        }
    return -1;
    }
    TreeNode* constructing(vector<int>& preorder, vector<int>& inorder , int &preindex , int inorderstartindex , int inorderendindex)
    {
                //base case:
        if(preindex >= preorder.size() ||inorderstartindex  > inorderendindex){
            return NULL;
        }

        // create the node for the each element in the preorder
        int element = preorder[preindex];
        preindex++;
        TreeNode* root = new TreeNode(element);
        
        // search the element of the preorder element in the inorder

        int position = search_element_Of_preorder_in_inorder(inorder , element);

        // after the getting the element in the inorder now we can find it like in hte root node which will be left subtreee and right subtree 

        root->left = constructing( preorder,  inorder ,preindex ,inorderstartindex , position-1);
        root->right = constructing( preorder,  inorder ,preindex ,position+1 ,inorderendindex );

        return root;
    }
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        int preindex = 0;
        int inorderstartindex = 0;
        int inorderendindex = inorder.size()-1;
        TreeNode* root = constructing(preorder, inorder ,preindex ,inorderstartindex ,inorderendindex);
        return root;
        
    }
};