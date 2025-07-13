class Solution {
public:
    void solve(TreeNode* root, vector<vector<int>>& temp, vector<int>& ans) {
        map<int, map<int, multiset<int>>> nodes;
        // map<x , map<y,nodes_storage>> map_name;
        // x-> horizontal level y-> level_order;
        // To understand it in better way in top view we inserting the nodes based on the horizontal level 
        // but here we insert the node on the horizontal level and in vector we will insert it based on the level order 
        // multiset denoted for storing the nodes
        queue<pair<TreeNode*, pair<int, int>>> q;
        // this is the way where we make the top view one 
        // queue<Node* , int >q;
        q.push(make_pair(root, make_pair(0, 0)));  // Fixed make_pair syntax

        while(!q.empty()) {
            pair<TreeNode*, pair<int, int>> front = q.front();  // Added parentheses
            q.pop();

            TreeNode* frontnode = front.first;
            // Extract the vertical and level information
            // x -> vertical
            int x = front.second.first;  
            // y -> level
            int y = front.second.second; 

            // where imp like we are inserting in the multiset where frontnode with coordinates of the 
            // horizontal level and vertical level 
            nodes[x][y].insert(frontnode->val);  // Changed data to val

            if(frontnode->left != NULL) {
                q.push(make_pair(frontnode->left, make_pair(x-1, y+1)));  // Fixed parameters
            }
            
            if(frontnode->right != NULL) {
                q.push(make_pair(frontnode->right, make_pair(x+1, y+1)));  // Fixed parameters
            }
        }

        // Moved this outside the while loop
        for(auto i : nodes) {
            vector<int> ans;
            for(auto q: i.second) {
                // Insert node values into the column vector
                ans.insert(ans.end(), q.second.begin(), q.second.end());  // Changed col to ans
            }
            temp.push_back(ans);
        }
    }

    vector<vector<int>> verticalTraversal(TreeNode* root) {
        vector<vector<int>> temp;
        vector<int> ans;
        solve(root, temp, ans);
        return temp;
    }
};