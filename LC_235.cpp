#include <bits/stdc++.h>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if (root == NULL) return NULL;

        // Both nodes lie in left subtree
        if (p->val < root->val && q->val < root->val) {
            return lowestCommonAncestor(root->left, p, q);
        }

        // Both nodes lie in right subtree
        if (p->val > root->val && q->val > root->val) {
            return lowestCommonAncestor(root->right, p, q);
        }

        // Split point (this is the LCA)
        return root;
    }
};

int main() {
    /*
            BST:
                 6
                / \
               2   8
              / \ / \
             0  4 7  9
               / \
              3   5

        p = 2, q = 8
        LCA = 6
    */

    TreeNode* root = new TreeNode(6);
    root->left = new TreeNode(2);
    root->right = new TreeNode(8);
    root->left->left = new TreeNode(0);
    root->left->right = new TreeNode(4);
    root->left->right->left = new TreeNode(3);
    root->left->right->right = new TreeNode(5);
    root->right->left = new TreeNode(7);
    root->right->right = new TreeNode(9);

    TreeNode* p = root->left;        // 2
    TreeNode* q = root->right;       // 8

    Solution sol;
    TreeNode* lca = sol.lowestCommonAncestor(root, p, q);

    cout << "Lowest Common Ancestor: " << lca->val << endl;

    return 0;
}
