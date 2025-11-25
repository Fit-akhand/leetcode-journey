#include <iostream>
#include <algorithm>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

class Solution {
public:
    int maxDepth(TreeNode *root, bool &balanced) {
        if (root == nullptr) {
            return 0;
        }

        int left = maxDepth(root->left, balanced) + 1;
        int right = maxDepth(root->right, balanced) + 1;

        if (abs(left - right) > 1) {
            balanced = false;
        }

        return max(left, right);
    }

    bool isBalanced(TreeNode* root) {
        bool balanced = true;
        maxDepth(root, balanced);
        return balanced;
    }
};

// Build tree using preorder input (-1 means NULL)
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
    cout << "Enter tree nodes in preorder (-1 for null):" << endl;
    // Example Input: 1 2 -1 -1 3 -1 -1  (Balanced)
    // Example Input: 1 2 3 -1 -1 -1 -1  (Not Balanced)

    TreeNode* root = buildTree();

    Solution sol;
    bool result = sol.isBalanced(root);

    cout << "\nTree is ";
    if (!result) cout << "NOT ";
    cout << "Balanced" << endl;

    return 0;
}
