class Solution {
public:
    void solve(Node* root, vector<int>&ans) {
        if (!root) { 
            return;
        }

        map<int, int> mp; 
        queue<pair<Node*, int>> q; 

        q.push(make_pair(root, 0));

        while (!q.empty()) {
            pair<Node*, int> front = q.front();
            q.pop();

            Node* frontnode = front.first;
            int hd = front.second; 
            mp[hd] = frontnode->data; 

            if (frontnode->left != NULL) {
                q.push(make_pair(frontnode->left, hd - 1));
            }
            if (frontnode->right != NULL) {
                q.push(make_pair(frontnode->right, hd + 1));
            }
        }

        for (auto i : mp) {
            ans.push_back(i.second);
        }
    }

    vector<int> bottomView(Node *root) {
        vector<int> ans;
        solve(root, ans);
        return ans;
    }
};