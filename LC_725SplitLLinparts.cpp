#include <iostream>
#include <vector>
using namespace std;

/**
 * Definition for singly-linked list.
 */
struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
    vector<ListNode*> splitListToParts(ListNode* head, int k) {
        // Step 1: Count total number of nodes
        int totalNodes = 0;
        ListNode* current = head;
        while (current) {
            totalNodes++;
            current = current->next;
        }

        // Step 2: Determine base size and extra nodes
        int baseSize = totalNodes / k;
        int extraNodes = totalNodes % k;

        // Step 3: Prepare result vector
        vector<ListNode*> result(k, nullptr);

        // Step 4: Split the list into k parts
        current = head;
        for (int i = 0; i < k && current; i++) {
            result[i] = current;

            // Determine size of the current part
            int currentPartSize = baseSize + (extraNodes-- > 0 ? 1 : 0);

            // Traverse to the end of this part
            for (int j = 1; j < currentPartSize; j++) {
                current = current->next;
            }

            // Break the list
            ListNode* nextPart = current->next;
            current->next = nullptr;
            current = nextPart;
        }

        return result;
    }
};

// ---------- Example usage (for testing in VS Code) ----------
int main() {
    // Create a sample linked list: 1 -> 2 -> 3 -> 4 -> 5 -> nullptr
    ListNode* head = new ListNode(1);
    head->next = new ListNode(2);
    head->next->next = new ListNode(3);
    head->next->next->next = new ListNode(4);
    head->next->next->next->next = new ListNode(5);

    int k = 3;
    Solution sol;
    vector<ListNode*> parts = sol.splitListToParts(head, k);

    // Print each part
    for (int i = 0; i < k; i++) {
        cout << "Part " << i + 1 << ": ";
        ListNode* temp = parts[i];
        while (temp) {
            cout << temp->val << " ";
            temp = temp->next;
        }
        cout << endl;
    }

    return 0;
}
