#include <bits/stdc++.h>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

// ------------------ Solution Class ------------------
class Solution {
public:
    int solve(TreeNode* p, TreeNode* q) {
        if (p == NULL && q == NULL) return 1;
        if (p == NULL || q == NULL) return 0;

        if (p->val == q->val) {
            int left = solve(p->left, q->left);
            int right = solve(p->right, q->right);
            return (left == 1 && right == 1) ? 1 : 0;
        } 
        return 0;
    }

    bool isSameTree(TreeNode* p, TreeNode* q) {
        return solve(p, q);
    }
};

// Sample tree builder (for quick testing)
TreeNode* buildTree() {
    int x;
    cin >> x;
    if (x == -1) return NULL;
    TreeNode* root = new TreeNode(x);
    root->left = buildTree();
    root->right = buildTree();
    return root;
}

// ------------------ Main Function ------------------
int main() {
    cout << "Enter Tree 1 values (-1 for NULL): ";
    TreeNode* p = buildTree();

    cout << "Enter Tree 2 values (-1 for NULL): ";
    TreeNode* q = buildTree();

    Solution s;
    bool ans = s.isSameTree(p, q);

    cout << (ans ? "Trees are SAME\n" : "Trees are NOT same\n");

    return 0;
}
