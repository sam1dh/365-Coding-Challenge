class Solution {
public:
    vector<int>final;
    void preorder(TreeNode* root){
         if(root == NULL)
        {
            return;
        }
        stack<TreeNode*>st;
        st.push(root);
       
        while(!st.empty())
        {
            TreeNode* top = st.top();
             st.pop();
            final.push_back(top->val);
            if(top->right!=NULL)
            {
                st.push(top->right);
            }
            if(top->left!=NULL)
            {
                st.push(top->left);
            }
        }
    }
    vector<int> preorderTraversal(TreeNode* root) {
        preorder(root);
        return final;
    }
};