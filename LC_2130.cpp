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
    int pairSum(ListNode* head) {
        // Step 1: Find the middle of the list
        ListNode* slow = head;
        ListNode* fast = head;
        while (fast && fast->next) {
            slow = slow->next;
            fast = fast->next->next;
        }

        // Step 2: Reverse the second half
        ListNode* prev = nullptr;
        while (slow) {
            ListNode* nextNode = slow->next;
            slow->next = prev;
            prev = slow;
            slow = nextNode;
        }

        // Step 3: Calculate twin sums
        int maxSum = 0;
        ListNode* first = head;
        ListNode* second = prev;
        while (second) {
            int currSum = first->val + second->val;
            maxSum = max(maxSum, currSum);
            first = first->next;
            second = second->next;
        }
        return maxSum;
    }
};

// Helper function to create a linked list
ListNode* createList(vector<int> vals) {
    if (vals.empty()) return nullptr;
    ListNode* head = new ListNode(vals[0]);
    ListNode* curr = head;
    for (int i = 1; i < vals.size(); i++) {
        curr->next = new ListNode(vals[i]);
        curr = curr->next;
    }
    return head;
}

int main() {
    Solution sol;

    // Example test case
    vector<int> vals = {5, 4, 2, 1};
    ListNode* head = createList(vals);

    cout << "Maximum Twin Sum: " << sol.pairSum(head) << endl;

    return 0;
}
