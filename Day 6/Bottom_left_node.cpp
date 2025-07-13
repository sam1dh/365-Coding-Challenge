class Solution {
public:
     void solve(TreeNode* root , vector<int>& ans , int level)
    {
        if(root == NULL)
        {
            return;
        }
        if(ans.size() == level)
        {
            ans.push_back(root->val);
        }
        solve(root->left , ans , level+1);
        solve(root->right , ans , level+1);
    }
    int findBottomLeftValue(TreeNode* root) {
        vector<int> ans;
        int level = 0;
        solve(root , ans , level);
        int a = ans.back();
        return a;
      
    }
};