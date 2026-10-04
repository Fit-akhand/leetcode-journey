class Solution {
public:
    Node* copyRandomList(Node* head) {

        if (head == NULL) {
            return NULL;
        }

        unordered_map<Node*, Node*> mp;

        // Step 1: Create copies
        Node* temp = head;

        while (temp != NULL) {
            Node* copy = new Node(temp->val);

            mp[temp] = copy;

            temp = temp->next;
        }

        // Step 2: Connect next and random
        temp = head;

        while (temp != NULL) {
            Node* copy = mp[temp];

            copy->next = mp[temp->next];
            copy->random = mp[temp->random];

            temp = temp->next;
        }

        return mp[head];
    }
};