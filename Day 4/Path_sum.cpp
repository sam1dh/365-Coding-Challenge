class Solution {
public:
    bool finalans(TreeNode* root , int targetSum , int sum)
    {
        // base case
        if(root == NULL)
        {
            return false;
        }
        sum = sum + root->val;
        // base case
        if(root->left == NULL && root->right == NULL)
        {
            if(targetSum == sum)
            {
                return true;
            }
            else
            {
                return false;
            }
        }
        bool leftans = finalans(root->left , targetSum ,sum);
        bool rightans = finalans(root->right , targetSum ,sum);
        return leftans||rightans;
    }
    bool hasPathSum(TreeNode* root, int targetSum) {
        int sum = 0;
        bool ans = finalans(root ,targetSum , sum);
        return ans;
    }
};