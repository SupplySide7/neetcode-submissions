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
            Node *copy = new Node(curr->val); copy->next = curr->next;
            curr->next = copy;
            curr = curr->next->next;
        } curr = head;
        while (curr) {
            Node *temp = curr->next;
            if (curr->random) temp->random = curr->random->next;
            else temp->random = nullptr;
            curr = temp->next;
        } curr = head; Node *head_copy = head->next;
        while (curr) {
            Node *copied = curr->next, *original = copied->next;
            curr->next = original;
            if (original) copied->next = original->next;
            else copied->next = nullptr;
            curr = curr->next;
        } return head_copy;
    }
};
