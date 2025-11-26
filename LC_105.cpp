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

    TreeNode* solve(vector<int>& preorder, vector<int>& inorder,
                    int &preorderIndex, int inorderStartindex,
                    int inorderEndindex, unordered_map<int, int> &mp) {

        if (preorderIndex >= preorder.size() || inorderStartindex > inorderEndindex) {
            return NULL;
        }

        int element = preorder[preorderIndex++];
        TreeNode* root = new TreeNode(element);
        int pos = mp[element];

        root->left = solve(preorder, inorder, preorderIndex, inorderStartindex, pos - 1, mp);
        root->right = solve(preorder, inorder, preorderIndex, pos + 1, inorderEndindex, mp);

        return root;
    }

    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        int preorderIndex = 0;
        int n = inorder.size();

        unordered_map<int, int> mp;
        for (int i = 0; i < n; i++) {
            mp[inorder[i]] = i;
        }

        return solve(preorder, inorder, preorderIndex, 0, n - 1, mp);
    }
};

// Helper: Print Inorder (to verify correct tree)
void printInorder(TreeNode* root) {
    if (!root) return;
    printInorder(root->left);
    cout << root->val << " ";
    printInorder(root->right);
}

int main() {
    // Example input:
    // preorder: 3 9 20 15 7
    // inorder: 9 3 15 20 7

    vector<int> preorder = {3, 9, 20, 15, 7};
    vector<int> inorder = {9, 3, 15, 20, 7};

    Solution s;
    TreeNode* root = s.buildTree(preorder, inorder);

    cout << "Inorder traversal of constructed tree: ";
    printInorder(root);
    cout << endl;

    return 0;
}
