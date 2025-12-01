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
public:
    vector<int> preorderTraversal(TreeNode* root) {
        vector<int> result;
        preorder(root, result);
        return result;
    }

    void preorder(TreeNode* node, vector<int>& result) {
        if (node == nullptr) return;

        result.push_back(node->val);   // root
        preorder(node->left, result);  // left
        preorder(node->right, result); // right
    }
};

int main() {
    // Example tree:
    //      1
    //       \
    //        2
    //       /
    //      3
    TreeNode* root = new TreeNode(1);
    root->right = new TreeNode(2);
    root->right->left = new TreeNode(3);

    Solution obj;
    vector<int> ans = obj.preorderTraversal(root);

    for (int x : ans) cout << x << " ";
    return 0;
}
