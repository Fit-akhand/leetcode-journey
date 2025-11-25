#include <iostream>
#include <vector>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

class Solution {
    void solve(TreeNode *root, int targetSum, int sum,
               vector<vector<int>> &ans, vector<int> temp) {
        if (root == nullptr) return;

        sum += root->val;
        temp.push_back(root->val);

        if (root->left == nullptr && root->right == nullptr) {
            if (sum == targetSum) {
                ans.push_back(temp);
            }
        }

        solve(root->left, targetSum, sum, ans, temp);
        solve(root->right, targetSum, sum, ans, temp);
    }

public:
    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
        vector<vector<int>> ans;
        vector<int> temp;
        solve(root, targetSum, 0, ans, temp);
        return ans;
    }
};

// Build a tree from preorder input (-1 = null)
TreeNode* buildTree() {
    int val;
    cin >> val;
    if (val == -1) return nullptr;

    TreeNode* root = new TreeNode(val);
    root->left = buildTree();
    root->right = buildTree();
    return root;
}

int main() {
    cout << "Enter preorder input (-1 for NULL):" << endl;
    // Example: 5 4 11 7 -1 -1 2 -1 -1 -1 8 13 -1 -1 4 5 -1 -1 1 -1 -1
    TreeNode* root = buildTree();

    cout << "Enter target sum: ";
    int target;
    cin >> target;

    Solution sol;
    vector<vector<int>> result = sol.pathSum(root, target);

    cout << "\nPaths with sum = " << target << ":\n";
    for (auto &path : result) {
        for (int &v : path) cout << v << " ";
        cout << endl;
    }

    if (result.empty()) {
        cout << "No path found!" << endl;
    }

    return 0;
}
