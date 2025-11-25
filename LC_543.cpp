#include <iostream>
#include <algorithm>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

// Optimized Solution (Single DFS traversal)
class Solution {
public:
    int diameter = 0;

    int height(TreeNode* root) {
        if (root == nullptr) return 0;

        int leftH = height(root->left);
        int rightH = height(root->right);

        diameter = max(diameter, leftH + rightH);

        return max(leftH, rightH) + 1;
    }

    int diameterOfBinaryTree(TreeNode* root) {
        height(root);
        return diameter;
    }
};

// Building tree using -1 as NULL indicator
TreeNode* buildTree() {
    int val;
    cin >> val;
    if (val == -1) return nullptr;

    TreeNode* root = new TreeNode(val);
    root->left = buildTree();
    root->right = buildTree();
    return root;
}

int main() {
    cout << "Enter tree nodes in pre-order (-1 for NULL):" << endl;
    // Example Input: 1 2 4 -1 -1 5 -1 -1 3 -1 6 -1 -1
    TreeNode* root = buildTree();

    Solution sol;
    int result = sol.diameterOfBinaryTree(root);

    cout << "\nDiameter of Binary Tree: " << result << endl;

    return 0;
}
