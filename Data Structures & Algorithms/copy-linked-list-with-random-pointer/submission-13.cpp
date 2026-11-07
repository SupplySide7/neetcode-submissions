/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/
class Solution {
public:
    Node* copyRandomList(Node* head) {
        if (!head) return nullptr;
        Node *curr = head;
        while (curr) {
            Node *copy = new Node(curr->val);
            copy->next = curr->next;
            curr->next = copy;
            curr = copy->next;
        }
        curr = head;
        while (curr) {
            Node *alias = curr->next;
            if (curr->random) alias->random = curr->random->next;
            else alias->random = nullptr;
            curr = alias->next;
        }
        Node *new_head = head->next;
        curr = head;
        while (curr) {
            Node *copy = curr->next;
            Node *original = copy->next;
            curr->next = original;
            if (original != nullptr) copy->next = original->next;
            else copy->next = nullptr;
            curr = original;
        } return new_head;
    }
};
