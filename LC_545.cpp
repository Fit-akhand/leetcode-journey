#include <iostream>
#include <vector>
using namespace std;

class Node {
public:
    int data;
    Node* left;
    Node* right;

    Node(int val) {
        data = val;
        left = NULL;
        right = NULL;
    }
};

class Solution {
public:
  
    void leftBoundary(Node *root, vector<int> &ans) {
        if (root == NULL) return;
        if (root->left == NULL && root->right == NULL) return;
        
        ans.push_back(root->data);
        
        if (root->left)
            leftBoundary(root->left, ans);
        else
            leftBoundary(root->right, ans);
    }
    
    void leafBoundary(Node *root, vector<int> &ans) {
        if (root == NULL) return;
        
        if (root->left == NULL && root->right == NULL) {
            ans.push_back(root->data);
            return;
        }
        
        leafBoundary(root->left, ans);
        leafBoundary(root->right, ans);
    }
    
    void rightBoundary(Node *root, vector<int> &ans) {
        if (root == NULL) return;
        if (root->left == NULL && root->right == NULL) return;
        
        if (root->right)
            rightBoundary(root->right, ans);
        else
            rightBoundary(root->left, ans);
        
        ans.push_back(root->data); 
    }
  
    vector<int> boundaryTraversal(Node *root) {
        vector<int> ans;
        
        if (root == NULL) return ans;
        
        ans.push_back(root->data);        // root
        
        leftBoundary(root->left, ans);    // left boundary
        
        leafBoundary(root->left, ans);    // left leaf
        leafBoundary(root->right, ans);   // right leaf
        
        rightBoundary(root->right, ans);  // right boundary
        
        return ans;
    }
};

int main() {

    /*
       Sample Tree:
               1
             /   \
            2     3
           / \   / \
          4   5 6   7
               \
                8
    */
    
    Node* root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    
    root->left->left = new Node(4);
    root->left->right = new Node(5);
    
    root->right->left = new Node(6);
    root->right->right = new Node(7);
    
    root->left->right->right = new Node(8);

    Solution s;
    vector<int> result = s.boundaryTraversal(root);

    cout << "Boundary Traversal: ";
    for (int x : result) {
        cout << x << " ";
    }
    cout << endl;

    return 0;
}
