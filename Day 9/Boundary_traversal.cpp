
class Solution {
  public:
    void leftboundary(Node*root , vector<int>&ans)
    {
        if(root == NULL)
        {
            return;
        }
        // agar root node mila leaf boundary me toh return karlo 
        if(root->left == NULL && root->right == NULL)
        {
            return;
        }
        ans.push_back(root->data);
        // agar tum left ja sakte ho toh jao and left ya right dono ja sakte ho but ek 
        // side ja sakte ho
        if(root->left!= NULL)
        {
            leftboundary(root->left , ans);
        }
        else{
            leftboundary(root->right , ans);
        }
        
    }
    void leafnode(Node *root , vector<int>&ans)
    {
        if(root == NULL)
        {
            return;
        }
        if(root->left == NULL && root->right == NULL)
        {
            ans.push_back(root->data);
        }
        leafnode(root->left , ans);
        leafnode(root->right , ans);
        
    }
    void rightboundary(Node *root , vector<int>&ans)
    {
        if(root == NULL)
        {
            return;
        }
        // agar leaf node mil jaye to return kardo 
        if(root->left == NULL && root->right == NULL)
        {
            return;
        }
        // agar right me jana possible he toh right me jaye or vese toh right ya left me 
        // dono me se ek side ja sakte ho 
        if(root->right!= NULL)
        {
            rightboundary(root->right , ans);
        }
        else{
            rightboundary(root->left ,ans);
        }
        ans.push_back(root->data);
    }
    void boundaryTraversal(Node* root , vector<int>&ans)
    {
        if(root == NULL)
        {
            return ;
        }
        ans.push_back(root->data);
        leftboundary(root->left,ans);
        leafnode(root->left,ans);
        leafnode(root->right,ans);
        rightboundary(root->right,ans);
    }
    vector<int> boundaryTraversal(Node *root) {
        vector<int>ans;
        boundaryTraversal(root,ans);
        return ans;
    }
};