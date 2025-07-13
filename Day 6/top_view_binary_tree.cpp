/*
struct Node
{
    int data;
    Node* left;
    Node* right;
};
*/
class Solution {
  public:
  void solve(Node* root , vector<int>&ans)
  {
      queue<pair<Node*,int>>q;
      map<int ,int>mp;
      
      // level order traversal pattern;
      q.push(make_pair(root , 0));
      
      while(!q.empty())
      {
          pair<Node*,int> temp = q.front();
          q.pop();
          
          Node*frontnode = temp.first;
          int hd = temp.second;
          
          if(mp.find(hd)==mp.end())
          {
              mp[hd] = frontnode->data ;
          }
          
          if(frontnode->left != NULL)
          {
              q.push(make_pair(frontnode->left,hd-1));
          }
          
          if(frontnode->right != NULL)
          {
              q.push(make_pair(frontnode->right,hd+1));
          }
      }
      for(auto i : mp)
      {
          ans.push_back(i.second);
      }
  }
    vector<int> topView(Node *root) {
        vector<int> ans;
        solve(root , ans);
        return ans;
    }
};