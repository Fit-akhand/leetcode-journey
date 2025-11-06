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
    ListNode* deleteMiddle(ListNode* head) {
        if (head == nullptr || head->next == nullptr) {
            // For LeetCode, don't delete memory (test harness manages it)
            return nullptr;
        }

        ListNode* slow = head;
        ListNode* fast = head;
        ListNode* prev = nullptr;

        while (fast != nullptr && fast->next != nullptr) {
            fast = fast->next->next;
            prev = slow;
            slow = slow->next;
        }

        // unlink the middle node
        prev->next = slow->next;

        // optional for VS Code (safe cleanup)
        delete slow;

        return head;
    }
};

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

// Helper to print linked list
void printList(ListNode* head) {
    while (head != nullptr) {
        cout << head->val;
        if (head->next) cout << " -> ";
        head = head->next;
    }
    cout << endl;
}

// Helper to free memory (for VS Code local testing)
void freeList(ListNode* head) {
    while (head != nullptr) {
        ListNode* temp = head;
        head = head->next;
        delete temp;
    }
}

// Main function for testing
int main() {
    Solution sol;

    // Example: [1, 3, 4, 7, 1, 2, 6]
    vector<int> vals = {1, 3, 4, 7, 1, 2, 6};
    ListNode* head = createList(vals);

    cout << "Original list: ";
    printList(head);

    head = sol.deleteMiddle(head);

    cout << "After deleting middle: ";
    printList(head);

    // Free allocated memory (important for VS Code)
    freeList(head);

    return 0;
}
