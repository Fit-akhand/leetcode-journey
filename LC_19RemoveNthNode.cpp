#include <iostream>
using namespace std;

// Definition for singly-linked list
struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        if (!head) return nullptr;

        ListNode *first = head;
        ListNode *second = head;

        // Move first n steps ahead
        for (int i = 0; i < n; i++) {
            first = first->next;
        }

        // If first is NULL, remove the head
        if (first == nullptr) {
            ListNode* newHead = head->next;
            delete head;
            return newHead;
        }

        // Move both pointers until first reaches the end
        while (first->next != nullptr) {
            first = first->next;
            second = second->next;
        }

        // Delete the target node
        ListNode* temp = second->next;
        second->next = temp->next;
        delete temp;

        return head;
    }
};

// Helper: create linked list from array
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

// Helper: print linked list
void printList(ListNode* head) {
    while (head) {
        cout << head->val << " ";
        head = head->next;
    }
    cout << endl;
}

int main() {
    int arr[] = {1, 2, 3, 4, 5};
    int n = sizeof(arr) / sizeof(arr[0]);

    ListNode* head = createList(arr, n);

    Solution s;
    int k = 2; // remove 2nd node from the end
    head = s.removeNthFromEnd(head, k);

    cout << "Linked List after removing " << k << "th node from end: ";
    printList(head);

    return 0;
}
