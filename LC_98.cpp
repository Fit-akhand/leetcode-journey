#include <iostream>
#include <climits>
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
    bool solve(TreeNode* root, long &prev) {
        if (root == NULL) {
            return true;
        }

        // Left subtree
        if (!solve(root->left, prev)) {
            return false;
        }

        // Check current node (increasing order)
        if (root->val <= prev) {
            return false;
        }
        prev = root->val;

        // Right subtree
        return solve(root->right, prev);
    }

    bool isValidBST(TreeNode* root) {
        long prev = LONG_MIN;
        return solve(root, prev);
    }
};

int main() {
    /*
          5
         / \
        3   7
       / \
      2   4
     (Valid BST)
    */

    TreeNode* root = new TreeNode(5);
    root->left = new TreeNode(3);
    root->right = new TreeNode(7);
    root->left->left = new TreeNode(2);
    root->left->right = new TreeNode(4);

    Solution s;

    if (s.isValidBST(root))
        cout << "Valid BST" << endl;
    else
        cout << "Invalid BST" << endl;

    return 0;
}
