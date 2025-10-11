#include <bits/stdc++.h>
using namespace std;

/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* prev;
    Node* next;
    Node* child;
};
*/

// Complete Node definition for VS Code
class Node {
public:
    int val;
    Node* prev;
    Node* next;
    Node* child;

    Node(int _val) {
        val = _val;
        prev = NULL;
        next = NULL;
        child = NULL;
    }
};

class Solution {
public:
    // Recursive helper to flatten list
    Node* solve(Node* head) {
        if (!head) return NULL;

        Node* it = head;   // iterator
        Node* tail = head; // keeps track of last node

        while (it) {
            Node* temp = it->next; // store next pointer before changes

            // if current node has a child
            if (it->child) {
                Node* childtail = solve(it->child); // flatten child first

                // connect current node with child
                it->next = it->child;
                it->child->prev = it;

                // connect child's tail with next node (if any)
                if (temp) {
                    childtail->next = temp;
                    temp->prev = childtail;
                }

                // remove child pointer
                it->child = NULL;

                // update tail
                tail = childtail;
            } else {
                tail = it;
            }

            // move to next node
            it = temp;
        }

        return tail;
    }

    Node* flatten(Node* head) {
        solve(head);
        return head;
    }
};

// Helper function to print doubly linked list
void printList(Node* head) {
    Node* temp = head;
    while (temp) {
        cout << temp->val << " ";
        temp = temp->next;
    }
    cout << endl;
}

// Example usage
int main() {
    // Level 1: 1 - 2 - 3 - 4 - 5
    Node* head = new Node(1);
    head->next = new Node(2);
    head->next->prev = head;
    head->next->next = new Node(3);
    head->next->next->prev = head->next;
    head->next->next->next = new Node(4);
    head->next->next->next->prev = head->next->next;
    head->next->next->next->next = new Node(5);
    head->next->next->next->next->prev = head->next->next->next;

    // Add child: 3 → 6 - 7
    head->next->next->child = new Node(6);
    head->next->next->child->next = new Node(7);
    head->next->next->child->next->prev = head->next->next->child;

    Solution s;
    Node* flat = s.flatten(head);

    cout << "Flattened list: ";
    printList(flat);

    return 0;
}
