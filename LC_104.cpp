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
    int maxDepth(TreeNode* root) {
        if(root == NULL){
            return 0;
        }
        int leftHeight = maxDepth(root->left) + 1;
        int rightHeight = maxDepth(root->right) + 1;
        return max(leftHeight, rightHeight);
    }
};

// Build tree using pre-order input where -1 means NULL
TreeNode* buildTree() {
    int val;
    cin >> val;
    if(val == -1) return nullptr;

    TreeNode* root = new TreeNode(val);
    root->left = buildTree();
    root->right = buildTree();
    return root;
}

int main() {
    cout << "Enter tree in pre-order (-1 for NULL):" << endl;
    // Example input: 1 2 4 -1 -1 5 -1 -1 3 -1 -1
    TreeNode* root = buildTree();

    Solution sol;
    int result = sol.maxDepth(root);

    cout << "\nMaximum Depth of Tree: " << result << endl;
    return 0;
}
