#include <iostream>
#include <vector>
#include <unordered_map>
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

    TreeNode* solve(vector<int>& postorder, vector<int>& inorder,
                    int &postorderIndex, int inorderStart,
                    int inorderEnd, unordered_map<int, int> &mp) {

        if (postorderIndex < 0 || inorderStart > inorderEnd) {
            return NULL;
        }

        int element = postorder[postorderIndex--];
        TreeNode* root = new TreeNode(element);

        int pos = mp[element];

        // Build right subtree first
        root->right = solve(postorder, inorder, postorderIndex,
                            pos + 1, inorderEnd, mp);

        // Build left subtree
        root->left = solve(postorder, inorder, postorderIndex,
                           inorderStart, pos - 1, mp);

        return root;
    }

    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        int postorderIndex = postorder.size() - 1;
        int n = inorder.size();

        unordered_map<int, int> mp;
        for (int i = 0; i < n; i++) {
            mp[inorder[i]] = i;
        }

        return solve(postorder, inorder, postorderIndex,
                     0, n - 1, mp);
    }
};

// Helper: Print inorder to verify
void printInorder(TreeNode* root) {
    if (!root) return;
    printInorder(root->left);
    cout << root->val << " ";
    printInorder(root->right);
}

int main() {

    // Example input:
    // inorder:   9 3 15 20 7
    // postorder: 9 15 7 20 3

    vector<int> inorder   = {9, 3, 15, 20, 7};
    vector<int> postorder = {9, 15, 7, 20, 3};

    Solution s;
    TreeNode* root = s.buildTree(inorder, postorder);

    cout << "Inorder traversal of constructed tree: ";
    printInorder(root);
    cout << endl;

    return 0;
}
