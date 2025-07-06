class Solution {
public:
  
    int countNodes(TreeNode* root) {
        int count = 0;
          if(root == NULL)
        {
            return 0;
        }
        queue<TreeNode*>q;
        q.push(root);
        while(!q.empty())
        {
            TreeNode*front = q.front();
            q.pop();
            count++;
            if(front->left != NULL)
            {
                q.push(front->left);
            }
            if(front->right != NULL)
            {
                q.push(front->right);
            }
        }
        return count;
    }
};