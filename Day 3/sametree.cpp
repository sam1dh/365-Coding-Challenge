class Solution {
public:
    vector<string> ans1;
    vector<string> ans2;

    void levelorder_1(TreeNode* p) {
        if (p == NULL) {
            return;
        }
        queue<TreeNode*> q;
        q.push(p);
        while (!q.empty()) {
            TreeNode* front = q.front();
            q.pop();

            if (front != NULL) {
                ans1.push_back(to_string(front->val));
                q.push(front->left);
                q.push(front->right);
            } else {
                ans1.push_back("#");
            }
        }
    }

    void levelorder_2(TreeNode* q_root) {
        if (q_root == NULL) {
            return;
        }
        queue<TreeNode*> q1;
        q1.push(q_root);
        while (!q1.empty()) {
            TreeNode* front = q1.front();
            q1.pop();

            if (front != NULL) {
                ans2.push_back(to_string(front->val));
                q1.push(front->left);
                q1.push(front->right);
            } else {
                ans2.push_back("#");
            }
        }
    }

    bool isSameTree(TreeNode* p, TreeNode* q) {
        levelorder_1(p);
        levelorder_2(q);

        return ans1 == ans2;
    }
};
