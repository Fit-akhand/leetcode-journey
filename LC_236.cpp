#include <iostream>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

// Your LCA Logic
class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if (root == nullptr) return nullptr;
        if (root == p || root == q) return root;

        TreeNode* left = lowestCommonAncestor(root->left, p, q);
        TreeNode* right = lowestCommonAncestor(root->right, p, q);

        if (left && right) return root;
        return left ? left : right;
    }
};

// Build tree using preorder where -1 = null
TreeNode* buildTree() {
    int val;
    cin >> val;
    if (val == -1) return nullptr;

    TreeNode* root = new TreeNode(val);
    root->left = buildTree();
    root->right = buildTree();
    return root;
}

// Find pointer to node by value
TreeNode* findNode(TreeNode* root, int value) {
    if (!root) return nullptr;
    if (root->val == value) return root;
    TreeNode* left = findNode(root->left, value);
    if (left) return left;
    return findNode(root->right, value);
}

int main() {
    cout << "Enter tree nodes in preorder (-1 for NULL):\n";
    // Example: 3 5 6 -1 -1 2 7 -1 -1 4 -1 -1 1 0 -1 -1 8 -1 -1

    TreeNode* root = buildTree();

    cout << "Enter values of p and q: ";
    int pVal, qVal;
    cin >> pVal >> qVal;

    TreeNode* p = findNode(root, pVal);
    TreeNode* q = findNode(root, qVal);

    if (!p || !q) {
        cout << "One of the nodes not found!" << endl;
        return 0;
    }

    Solution sol;
    TreeNode* lca = sol.lowestCommonAncestor(root, p, q);
    cout << "LCA: " << lca->val << endl;

    return 0;
}
