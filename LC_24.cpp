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

// Solution class
class Solution {
public:
    ListNode* swapPairs(ListNode* head) {
        // Dummy node for easier pointer manipulation
        ListNode* dummy = new ListNode(0);
        dummy->next = head;
        ListNode* curr = dummy;

        while (curr->next && curr->next->next) {
            ListNode* first = curr->next;
            ListNode* second = curr->next->next;

            // Swapping
            first->next = second->next;
            second->next = first;
            curr->next = second;

            // Move to next pair
            curr = first;
        }

        return dummy->next;
    }
};

// Helper functions for testing
ListNode* createList(vector<int> vals) {
    ListNode* dummy = new ListNode(0);
    ListNode* tail = dummy;
    for (int v : vals) {
        tail->next = new ListNode(v);
        tail = tail->next;
    }
    return dummy->next;
}

void printList(ListNode* head) {
    while (head) {
        cout << head->val;
        if (head->next) cout << " -> ";
        head = head->next;
    }
    cout << endl;
}

// Main function
int main() {
    Solution sol;

    vector<int> vals = {1, 2, 3, 4};
    ListNode* head = createList(vals);

    cout << "Original list: ";
    printList(head);

    head = sol.swapPairs(head);

    cout << "After swapping pairs: ";
    printList(head);

    return 0;
}
