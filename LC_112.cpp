#include <iostream>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

class Solution {
public:
    bool check(TreeNode *root, int targetSum, int currentSum) {
        if (root == nullptr) return false;

        currentSum += root->val;

        // If leaf node, check if path sum matches
        if (root->left == nullptr && root->right == nullptr) {
            return currentSum == targetSum;
        }

        return check(root->left, targetSum, currentSum) ||
               check(root->right, targetSum, currentSum);
    }

    bool hasPathSum(TreeNode* root, int targetSum) {
        return check(root, targetSum, 0);
    }
};

// Build tree using preorder input -1 means NULL
TreeNode* buildTree() {
    int val;
    cin >> val;
    if (val == -1) return nullptr;

    TreeNode* node = new TreeNode(val);
    node->left = buildTree();
    node->right = buildTree();
    return node;
}

int main() {
    cout << "Enter tree nodes in preorder (-1 for NULL):" << endl;
    // Example: 5 4 11 7 -1 -1 2 -1 -1 -1 8 13 -1 -1 4 -1 -1
    TreeNode* root = buildTree();

    cout << "Enter target sum: ";
    int target;
    cin >> target;

    Solution sol;
    bool result = sol.hasPathSum(root, target);

    if (result)
        cout << "\nValid path exists!" << endl;
    else
        cout << "\nNo valid path found." << endl;

    return 0;
}
