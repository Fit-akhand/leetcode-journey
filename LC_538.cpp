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

    TreeNode* convertBST(TreeNode* root) {
        int count = 0;
        return addBST(root, count);
    }
};

// Helper: inorder traversal to verify output
void inorder(TreeNode* root) {
    if (!root) return;
    inorder(root->left);
    cout << root->val << " ";
    inorder(root->right);
}

int main() {
    /*
        Original BST:
              5
             / \
            2   13

        After Convert BST to GST:
              18
             /  \
           20    13
    */

    TreeNode* root = new TreeNode(5);
    root->left = new TreeNode(2);
    root->right = new TreeNode(13);

    Solution sol;
    root = sol.convertBST(root);

    cout << "Inorder after conversion: ";
    inorder(root);
    cout << endl;

    return 0;
}
