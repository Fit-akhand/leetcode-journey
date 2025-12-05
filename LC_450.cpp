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

    int getmax(TreeNode* root) {
        if (root == NULL) return -1;
        while (root->right != NULL) {
            root = root->right;
        }
        return root->val;
    }

    TreeNode* deleteNode(TreeNode* root, int key) {
        if (root == NULL) return NULL;

        if (root->val == key) {

            // Case 1: No child
            if (root->left == NULL && root->right == NULL) {
                delete root;
                return NULL;
            }

            // Case 2: One left child
            if (root->left != NULL && root->right == NULL) {
                TreeNode* child = root->left;
                delete root;
                return child;
            }

            // Case 3: One right child
            if (root->left == NULL && root->right != NULL) {
                TreeNode* child = root->right;
                delete root;
                return child;
            }

            // Case 4: Two children
            int replaceValue = getmax(root->left);
            root->val = replaceValue;
            root->left = deleteNode(root->left, replaceValue);
            return root;
        }
        else {
            if (key > root->val) {
                root->right = deleteNode(root->right, key);
            } else {
                root->left = deleteNode(root->left, key);
            }
        }
        return root;
    }
};

void inorder(TreeNode* root) {
    if (root == NULL) return;
    inorder(root->left);
    cout << root->val << " ";
    inorder(root->right);
}

int main() {
    // Build a sample BST
    TreeNode* root = new TreeNode(10);
    root->left = new TreeNode(5);
    root->right = new TreeNode(20);
    root->left->left = new TreeNode(3);
    root->left->right = new TreeNode(7);
    root->right->right = new TreeNode(30);

    Solution obj;

    cout << "Inorder before deletion: ";
    inorder(root);
    cout << endl;

    int key = 20;  // key to delete
    root = obj.deleteNode(root, key);

    cout << "Inorder after deletion: ";
    inorder(root);
    cout << endl;

    return 0;
}
