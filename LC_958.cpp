#include <iostream>
#include <queue>
using namespace std;

// Definition for a binary tree node
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;

    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *l, TreeNode *r) : val(x), left(l), right(r) {}
};

class Solution {
public:
    bool isCompleteTree(TreeNode* root) {
        queue<TreeNode*> q;
        q.push(root);

        bool nullFound = false;

        while (!q.empty()) {
            TreeNode* front = q.front();
            q.pop();

            if (front == nullptr) {
                nullFound = true;
            } else {
                if (nullFound) return false;
                q.push(front->left);
                q.push(front->right);
            }
        }
        return true;
    }
};

int main() {
    /*
        Example Tree:
              1
             / \
            2   3
           / \  /
          4  5 6
        (Complete Binary Tree)
    */

    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->left->left = new TreeNode(4);
    root->left->right = new TreeNode(5);
    root->right->left = new TreeNode(6);

    Solution sol;
    bool result = sol.isCompleteTree(root);

    if (result)
        cout << "Tree is Complete Binary Tree" << endl;
    else
        cout << "Tree is NOT Complete Binary Tree" << endl;

    return 0;
}
