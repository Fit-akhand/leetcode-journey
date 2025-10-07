#include <iostream>
using namespace std;

/* Definition for singly-linked list. */
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(nullptr) {}
};

class Solution {
public:
    ListNode *detectCycle(ListNode *head) {
        if (!head || !head->next) return nullptr;

        ListNode *slow = head;
        ListNode *fast = head;

        // Step 1: Detect if a cycle exists
        while (fast && fast->next) {
            slow = slow->next;
            fast = fast->next->next;
            if (slow == fast) break;  // meeting point
        }

        // No cycle detected
        if (!fast || !fast->next)
            return nullptr;

        // Step 2: Find the start of the cycle
        slow = head;
        while (slow != fast) {
            slow = slow->next;
            fast = fast->next;
        }

        return slow; // start of cycle
    }
};

// Helper functions for VS Code testing
ListNode* createCyclicList() {
    ListNode* head = new ListNode(3);
    ListNode* node2 = new ListNode(2);
    ListNode* node3 = new ListNode(0);
    ListNode* node4 = new ListNode(-4);

    head->next = node2;
    node2->next = node3;
    node3->next = node4;
    node4->next = node2;  // creates cycle at node2

    return head;
}

int main() {
    Solution s;
    ListNode* head = createCyclicList();
    ListNode* cycleStart = s.detectCycle(head);

    if (cycleStart)
        cout << "Cycle starts at node with value: " << cycleStart->val << endl;
    else
        cout << "No cycle detected." << endl;

    return 0;
}
