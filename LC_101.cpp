#include <bits/stdc++.h>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

// ---------------- Solution Class ----------------
class Solution {
public:

    int solve(TreeNode* p, TreeNode* q) {
        if (p == NULL && q == NULL) return 1;
        if (p == NULL || q == NULL) return 0;

        if (p->val == q->val) {
            int left = solve(p->left, q->right);   // mirror check
            int right = solve(p->right, q->left);
            return (left == 1 && right == 1) ? 1 : 0;
        } 
        return 0;
    }

    bool isSymmetric(TreeNode* root) {
        if (root == NULL) return true;
        return solve(root->left, root->right);
    }
};

// --------------- Build Tree Function ---------------
TreeNode* buildTree() {
    int x;
    cin >> x;
    if (x == -1) return NULL;

    TreeNode* root = new TreeNode(x);
    root->left = buildTree();
    root->right = buildTree();
    return root;
}

// --------------------- MAIN -----------------------
int main() {
    cout << "Enter tree nodes in preorder (-1 for NULL):\n";
    TreeNode* root = buildTree();

    Solution s;
    bool ans = s.isSymmetric(root);

    cout << "\nIs the tree symmetric? ";
    cout << (ans ? "YES" : "NO") << endl;

    return 0;
}
