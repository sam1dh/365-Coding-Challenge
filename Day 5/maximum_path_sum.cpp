class Solution {
public:
    int maxPathSum(TreeNode* root) {
        int maxi = INT_MIN;
        helper(root, maxi);
        return maxi;
    }
    
    int helper(TreeNode* root, int& maxi) {
        if (root == nullptr) {
            return 0;
        }

        int leftMaxPath = max(0, helper(root->left, maxi));
        int rightMaxPath = max(0, helper(root->right, maxi));
        maxi = max(maxi, leftMaxPath + rightMaxPath + root->val);
        return max(leftMaxPath, rightMaxPath) + root->val;
    }
};