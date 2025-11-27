#include <bits/stdc++.h>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution {
    // DFS helper to capture right-side view
    vector<int> solve(TreeNode* root, int depth, vector<int>& ans) {
        if (root == NULL) {
            return ans;
        }

        // First time at this depth → add node (rightmost)
        if (depth == ans.size()) {
            ans.push_back(root->val);
        }

        solve(root->right, depth + 1, ans);
        solve(root->left, depth + 1, ans);

        return ans;
    }

public:
    vector<int> rightSideView(TreeNode* root) {
        vector<int> ans;
        solve(root, 0, ans);
        return ans;
    }
};

// Helper to build tree from level-order input (-1 = NULL)
TreeNode* buildTree(vector<int>& arr) {
    if (arr.size() == 0 || arr[0] == -1) return nullptr;

    TreeNode* root = new TreeNode(arr[0]);
    queue<TreeNode*> q;
    q.push(root);

    int i = 1;
    while (i < arr.size()) {
        TreeNode* curr = q.front();
        q.pop();

        // left child
        if (arr[i] != -1) {
            curr->left = new TreeNode(arr[i]);
            q.push(curr->left);
        }
        i++;

        // right child
        if (i < arr.size() && arr[i] != -1) {
            curr->right = new TreeNode(arr[i]);
            q.push(curr->right);
        }
        i++;
    }

    return root;
}

int main() {
    int n;
    cin >> n;

    vector<int> arr(n);
    for (int i = 0; i < n; i++) {
        cin >> arr[i];   // -1 means NULL
    }

    TreeNode* root = buildTree(arr);

    Solution s;
    vector<int> ans = s.rightSideView(root);

    for (int x : ans) {
        cout << x << " ";
    }

    return 0;
}
