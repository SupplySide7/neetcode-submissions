/* class Node {public: int val; Node* next; Node* random;
    Node(int _val) {val = _val; next = NULL; random = NULL;}};*/
class Solution {
public:
    Node* copyRandomList(Node* head) {
        if (!head) return nullptr;
        Node *curr = head;
        while (curr) {
            Node *copy = new Node(curr->val); Node *temp = curr->next;
            curr->next = copy; copy->next = temp; curr = temp;
        } curr = head;
        while (curr) {
            Node *copied = curr->next;
            curr->random? copied->random = curr->random->next : copied->random = nullptr;
            curr = copied->next;
        } curr = head;
        Node *newhead = head->next;
        while(curr) {
            Node *original = curr->next->next; Node *copied = curr->next;
            curr->next = original;
            original? copied->next = original->next : copied->next = nullptr;
            curr = original;
        } return newhead;
    }
};
