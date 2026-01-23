#include <bits/stdc++.h>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

class Solution {
public:
    TreeNode* addBST(TreeNode* root, int &count) {
        if (root == NULL) return NULL;

        addBST(root->right, count);
        count += root->val;
        root->val = count;
        addBST(root->left, count);

        return root;
    }

    TreeNode* bstToGst(TreeNode* root) {
        int count = 0;
        return addBST(root, count);
    }
};

// inorder print to verify result
void inorder(TreeNode* root) {
    if (!root) return;
    inorder(root->left);
    cout << root->val << " ";
    inorder(root->right);
}

int main() {
    /*
        Original BST:
              4
             / \
            1   6
               / \
              5   7

        GST Result:
             22
            /  \
          27    13
                \
                 7
    */

    TreeNode* root = new TreeNode(4);
    root->left = new TreeNode(1);
    root->right = new TreeNode(6);
    root->right->left = new TreeNode(5);
    root->right->right = new TreeNode(7);

    Solution sol;
    root = sol.bstToGst(root);

    cout << "Inorder after GST: ";
    inorder(root);
    cout << endl;

    return 0;
}
