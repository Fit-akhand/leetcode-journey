#include <iostream>
using namespace std;

// Definition of TreeNode
class TreeNode {
public:
    int val;
    TreeNode* left;
    TreeNode* right;

    TreeNode(int value) {
        val = value;
        left = nullptr;
        right = nullptr;
    }
};

class Solution {
public:
    int dfs(TreeNode* root, int curr) {
        if (root == nullptr)
            return 0;

        // Form the current number
        curr = curr * 10 + root->val;

        // If leaf node
        if (root->left == nullptr && root->right == nullptr)
            return curr;

        // Sum of left and right subtree
        return dfs(root->left, curr) + dfs(root->right, curr);
    }

    int sumNumbers(TreeNode* root) {
        return dfs(root, 0);
    }
};

int main() {
    /*
            4
          /   \
         9     0
        / \
       5   1

    Numbers formed:
    495
    491
    40

    Sum = 1026
    */

    TreeNode* root = new TreeNode(4);
    root->left = new TreeNode(9);
    root->right = new TreeNode(0);
    root->left->left = new TreeNode(5);
    root->left->right = new TreeNode(1);

    Solution obj;
    cout << "Sum of Root-to-Leaf Numbers: " << obj.sumNumbers(root) << endl;

    return 0;
}