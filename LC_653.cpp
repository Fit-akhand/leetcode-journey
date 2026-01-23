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
    void inorder(TreeNode* root, vector<int>& arr) {
        if (!root) return;
        inorder(root->left, arr);
        arr.push_back(root->val);
        inorder(root->right, arr);
    }

    bool findTarget(TreeNode* root, int k) {
        vector<int> arr;
        inorder(root, arr);

        int i = 0, j = arr.size() - 1;
        while (i < j) {
            int sum = arr[i] + arr[j];
            if (sum == k) return true;
            else if (sum < k) i++;
            else j--;
        }
        return false;
    }
};

int main() {
    /*
        BST:
             5
            / \
           3   6
          / \   \
         2   4   7
    */

    TreeNode* root = new TreeNode(5);
    root->left = new TreeNode(3);
    root->right = new TreeNode(6);
    root->left->left = new TreeNode(2);
    root->left->right = new TreeNode(4);
    root->right->right = new TreeNode(7);

    Solution sol;
    int k = 9;

    cout << (sol.findTarget(root, k) ? "true" : "false") << endl;

    return 0;
}
