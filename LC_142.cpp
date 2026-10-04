#include <iostream>
using namespace std;

struct ListNode {
    int val;
    ListNode* next;

    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    ListNode* detectCycle(ListNode* head) {

        if (head == NULL) {
            return NULL;
        }

        ListNode* slow = head;
        ListNode* fast = head;

        // Phase 1: Detect cycle
        while (fast != NULL && fast->next != NULL) {

            slow = slow->next;
            fast = fast->next->next;

            if (slow == fast) {

                // Phase 2: Find cycle starting point
                ListNode* prev = head;

                while (prev != slow) {
                    prev = prev->next;
                    slow = slow->next;
                }

                return prev;
            }
        }

        return NULL;
    }
};

int main() {

    // Create nodes
    ListNode* n1 = new ListNode(1);
    ListNode* n2 = new ListNode(2);
    ListNode* n3 = new ListNode(3);
    ListNode* n4 = new ListNode(4);

    // Create linked list
    n1->next = n2;
    n2->next = n3;
    n3->next = n4;

    // Create cycle:
    // 1 -> 2 -> 3 -> 4
    //           ^    |
    //           |____|
    n4->next = n3;

    Solution solution;

    ListNode* cycleStart = solution.detectCycle(n1);

    if (cycleStart != NULL) {
        cout << "Cycle starts at node: "
             << cycleStart->val << endl;
    }
    else {
        cout << "No cycle found" << endl;
    }

    return 0;
}