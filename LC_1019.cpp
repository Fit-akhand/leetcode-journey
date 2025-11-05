#include <bits/stdc++.h>
using namespace std;

// Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
    vector<int> nextLargerNodes(ListNode* head) {
        vector<int> ans;
        stack<pair<int,int>> st; // {value, index}
        ListNode *temp = head;
        int i = 0;

        while (temp != NULL) {
            ans.push_back(0);  // reserve place for this node

            while (!st.empty() && st.top().first < temp->val) {
                ans[st.top().second] = temp->val;
                st.pop();
            }

            st.push({temp->val, i});
            i++;
            temp = temp->next;
        }

        // Remaining nodes already have 0 as default next greater value
        return ans;
    }
};

// Optional: to test in VS Code
int main() {
    // Example: 2 -> 1 -> 5
    ListNode* head = new ListNode(2, new ListNode(1, new ListNode(5)));

    Solution sol;
    vector<int> result = sol.nextLargerNodes(head);

    cout << "Next larger nodes: ";
    for (int val : result) cout << val << " ";
    cout << endl;

    return 0;
}
