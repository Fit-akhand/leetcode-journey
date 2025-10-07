#include <iostream>
using namespace std;

/* Definition for singly-linked list. */
struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
    ListNode* partition(ListNode* head, int x) {
        ListNode *smallhead = nullptr;
        ListNode *smalltail = nullptr;
        ListNode *greaterhead = nullptr;
        ListNode *greatertail = nullptr;

        ListNode *temp = head;

        while (temp != nullptr) {
            ListNode *newnode = new ListNode(temp->val);

            if (temp->val < x) {
                if (smallhead == nullptr) {
                    smallhead = smalltail = newnode;
                } else {
                    smalltail->next = newnode;
                    smalltail = newnode;
                }
            } else {
                if (greaterhead == nullptr) {
                    greaterhead = greatertail = newnode;
                } else {
                    greatertail->next = newnode;
                    greatertail = newnode;
                }
            }
            temp = temp->next;
        }

        // Connect the two lists
        if (smallhead == nullptr) return greaterhead;
        smalltail->next = greaterhead;
        return smallhead;
    }
};

// Helper functions for testing in VS Code
ListNode* createList(int arr[], int n) {
    if (n == 0) return nullptr;
    ListNode *head = new ListNode(arr[0]);
    ListNode *tail = head;
    for (int i = 1; i < n; i++) {
        tail->next = new ListNode(arr[i]);
        tail = tail->next;
    }
    return head;
}

void printList(ListNode *head) {
    while (head != nullptr) {
        cout << head->val;
        if (head->next) cout << " -> ";
        head = head->next;
    }
    cout << endl;
}

int main() {
    int arr[] = {1, 4, 3, 2, 5, 2};
    int n = sizeof(arr) / sizeof(arr[0]);
    ListNode *head = createList(arr, n);

    Solution s;
    ListNode *result = s.partition(head, 3);

    printList(result);
    return 0;
}
