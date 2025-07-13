class Solution {
public:
    vector<vector<int>> ans1;
 
    void levelordertravesal(TreeNode* root)
    {
        if(root == NULL)
        {
            return;
        }
        queue<TreeNode*>q;
        q.push(root);
        while(!q.empty())
        {
            int n = q.size();
            vector<int> ans;
            for(int i= 0 ; i<n ; i++)
            {
            TreeNode* front = q.front();
            q.pop();
            ans.push_back(front->val);
            if(front->left!=NULL)
            {
                q.push(front->left);
            }
            if(front->right!=NULL)
            {
                q.push(front->right);
            }
            }


           ans1.push_back(ans);
        }
         

    }
    vector<vector<int>> levelOrder(TreeNode* root) {
        levelordertravesal(root);
        return ans1;
    }
};