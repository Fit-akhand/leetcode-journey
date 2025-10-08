#include <iostream>
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
    ListNode* mergeTwoLists(ListNode* left, ListNode* right) {
        if (left == nullptr) return right;
        if (right == nullptr) return left;

        ListNode *ans = new ListNode(-1); // dummy node
        ListNode *mptr = ans;

        while (left && right) {
            if (left->val <= right->val) {
                mptr->next = left;
                left = left->next;
            } else {
                mptr->next = right;
                right = right->next;
            }
            mptr = mptr->next;
        }

        if (left) mptr->next = left;
        if (right) mptr->next = right;

        ListNode *result = ans->next;
        delete ans; // free dummy node memory
        return result;
    }
};

// Helper function to print a linked list
void printList(ListNode* head) {
    while (head) {
        cout << head->val << " ";
        head = head->next;
    }
    cout << endl;
}

// Helper function to create linked list from array
ListNode* createList(int arr[], int n) {
    if (n == 0) return nullptr;
    ListNode* head = new ListNode(arr[0]);
    ListNode* temp = head;
    for (int i = 1; i < n; i++) {
        temp->next = new ListNode(arr[i]);
        temp = temp->next;
    }
    return head;
}

int main() {
    int arr1[] = {1, 3, 5};
    int arr2[] = {2, 4, 6};

    ListNode* l1 = createList(arr1, 3);
    ListNode* l2 = createList(arr2, 3);

    Solution s;
    ListNode* merged = s.mergeTwoLists(l1, l2);

    cout << "Merged List: ";
    printList(merged);

    return 0;
}
