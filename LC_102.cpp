#include <bits/stdc++.h>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

// ------------------ Solution Class ------------------
class Solution {
public:

    void solve(TreeNode *root , vector<vector<int>>& ans){
        if(root == NULL){
            return;
        }
        vector<int> temp;
        queue<TreeNode*> q;

        q.push(root);
        q.push(NULL);

        while(!q.empty()){
            TreeNode *front = q.front();
            q.pop();

            if(front == NULL) {
                ans.push_back(temp);
                temp.clear();
                if(!q.empty()){
                    q.push(NULL);
                }
            }
            else{
                temp.push_back(front->val);

                if(front->left != NULL){
                    q.push(front->left);
                }
                if(front->right != NULL){
                    q.push(front->right);
                }
            }
        }
    }

    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> ans;
        solve(root, ans);
        return ans;
    }
};

// ------------------ Build Tree Function ------------------
TreeNode* buildTree() {
    int x;
    cin >> x;
    if(x == -1) return NULL;

    TreeNode* root = new TreeNode(x);
    root->left = buildTree();
    root->right = buildTree();
    return root;
}

// ------------------ Main Function ------------------
int main() {
    cout << "Enter tree values in preorder (-1 for NULL):\n";
    TreeNode* root = buildTree();

    Solution s;
    vector<vector<int>> ans = s.levelOrder(root);

    cout << "\nLevel Order Traversal:\n";
    for(auto &level : ans) {
        for(int x : level) cout << x << " ";
        cout << endl;
    }

    return 0;
}
