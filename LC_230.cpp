#include <iostream>
#include <vector>
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
public:

    void solve(TreeNode* root, vector<int>& ans) {
        if (root == NULL) return;

        solve(root->left, ans);
        ans.push_back(root->val);
        solve(root->right, ans);
    }

    int kthSmallest(TreeNode* root, int k) {
        vector<int> ans;
        solve(root, ans); // inorder → sorted for BST
        return ans[k - 1];
    }
};

int main() {
    // Example BST:
    //      5
    //     / \
    //    3   6
    //   / \
    //  2   4

    TreeNode* root = new TreeNode(5);
    root->left = new TreeNode(3);
    root->right = new TreeNode(6);
    root->left->left = new TreeNode(2);
    root->left->right = new TreeNode(4);

    Solution s;
    int k = 3;

    cout << "Kth smallest: " << s.kthSmallest(root, k) << endl;

    return 0;
}
