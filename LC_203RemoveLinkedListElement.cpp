#include <bits/stdc++.h>
using namespace std;

// Definition for singly-linked list
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
    ListNode* removeElements(ListNode* head, int val) {
        // Step 1: Remove leading nodes with matching value
        while (head != nullptr && head->val == val) {
            ListNode* temp = head;
            head = head->next;
            delete temp;
        }

        // Step 2: Handle remaining nodes
        if (head == nullptr) return nullptr;

        ListNode* curr = head;
        while (curr->next != nullptr) {
            if (curr->next->val == val) {
                ListNode* temp = curr->next;
                curr->next = curr->next->next;
                delete temp;
            } else {
                curr = curr->next;
            }
        }

        return head;
    }
};

// Helper to print linked list
void printList(ListNode* head) {
    while (head != nullptr) {
        cout << head->val;
        if (head->next) cout << " -> ";
        head = head->next;
    }
    cout << endl;
}

// Helper to create linked list from vector
ListNode* createList(const vector<int>& vals) {
    if (vals.empty()) return nullptr;
    ListNode* head = new ListNode(vals[0]);
    ListNode* curr = head;
    for (size_t i = 1; i < vals.size(); i++) {
        curr->next = new ListNode(vals[i]);
        curr = curr->next;
    }
    return head;
}

// Main function for testing
int main() {
    Solution sol;

    // Example list: 1 -> 2 -> 6 -> 3 -> 4 -> 5 -> 6
    vector<int> vals = {1, 2, 6, 3, 4, 5, 6};
    ListNode* head = createList(vals);

    cout << "Original list: ";
    printList(head);

    int val = 6;
    head = sol.removeElements(head, val);

    cout << "After removing " << val << ": ";
    printList(head);

    return 0;
}
