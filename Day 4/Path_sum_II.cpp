class Solution {
public:
    void finalsum(TreeNode* root , int targetSum , vector<vector<int>> &temp , vector<int> v , int sum)
    { 
        if(root == NULL)
        {
            return ;
        }
        sum = sum + root->val;
        v.push_back(root->val);
        if(root->left == NULL && root->right == NULL)
        {
            if(targetSum == sum)
            {
                temp.push_back(v);
            }
            else{
                return;
            }
        }
        finalsum( root->left , targetSum , temp , v , sum);
        finalsum( root->right , targetSum , temp , v , sum);


    }
    vector<vector<int>> pathSumII(TreeNode* root, int targetSum) {
        int sum = 0 ;
        vector<vector<int>> temp;
        vector<int>v;
        finalsum(root, targetSum , temp , v , sum);
        return temp;

    }
};