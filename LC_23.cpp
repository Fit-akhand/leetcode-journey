#include <iostream>
#include <vector>
#include <queue>
using namespace std;

// Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class compare {
public:
    bool operator()(ListNode* a, ListNode* b) {
        return a->val > b->val; // min heap
    }
};

class Solution {
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        priority_queue<ListNode*, vector<ListNode*>, compare> pq;

        // Push first node of each list
        for (ListNode* node : lists) {
            if (node != nullptr)
                pq.push(node);
        }

        ListNode* head = nullptr;
        ListNode* tail = nullptr;

        while (!pq.empty()) {
            ListNode* front = pq.top();
            pq.pop();

            if (head == nullptr) {
                head = front;
                tail = front;
            } else {
                tail->next = front;
                tail = front;
            }

            if (front->next != nullptr) {
                pq.push(front->next);
            }
        }
        return head;
    }
};

// Helper to create linked list from vector
ListNode* createList(vector<int> arr) {
    if (arr.empty()) return nullptr;

    ListNode* head = new ListNode(arr[0]);
    ListNode* temp = head;

    for (int i = 1; i < arr.size(); i++) {
        temp->next = new ListNode(arr[i]);
        temp = temp->next;
    }
    return head;
}

// Helper to print list
void printList(ListNode* head) {
    while (head) {
        cout << head->val << " ";
        head = head->next;
    }
    cout << endl;
}

int main() {
    // Example input
    vector<int> a = {1, 4, 5};
    vector<int> b = {1, 3, 4};
    vector<int> c = {2, 6};

    ListNode* l1 = createList(a);
    ListNode* l2 = createList(b);
    ListNode* l3 = createList(c);

    vector<ListNode*> lists = {l1, l2, l3};

    Solution obj;
    ListNode* result = obj.mergeKLists(lists);

    cout << "Merged List: ";
    printList(result);

    return 0;
}
