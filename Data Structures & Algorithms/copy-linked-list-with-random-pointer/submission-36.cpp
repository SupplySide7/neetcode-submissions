/*Definition for a Node.
class Node {public: int val; Node* next; Node* random;    
    Node(int _val) {val = _val; next = NULL; random = NULL;}};*/
class Solution {
public:
    Node* copyRandomList(Node* head) {if (!head) return nullptr;
        Node *curr = head;
        while (curr) {
            Node *temp = curr->next;
            Node *copy = new Node(curr->val); copy->next = curr->next;
            curr->next = copy; curr = temp;
        } curr = head;
        while (curr) {
            Node *copied = curr->next;
            if (curr->random) {Node *random = curr->random; copied->random = random->next;}
            else copied->random = nullptr;
            curr = curr->next->next;
        } curr = head;
        Node *newhead = head->next;
        while (curr) {
            Node *copy = curr->next, *source = curr->next->next;
            curr->next = source;
            if (source) copy->next = source->next;
            else copy->next = nullptr;
            curr = source;
        } return newhead;
    }
};
