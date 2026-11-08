/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */

class Solution {
public:
    void reorderList(ListNode* head) {
        // cut list in half
        ListNode *fast = head->next, *slow = head;
        while (fast && fast->next) {
            fast = fast->next->next;
            slow = slow->next;
        }
        // reverse second half of list
        ListNode *curr = slow->next, *prev = nullptr;
        slow->next = nullptr; // first half of list ends here now
        while (curr) {
            ListNode *temp = curr->next;
            curr->next = prev;
            prev = curr;
            curr = temp;
        }
        curr = prev; // head of reversed second half
        // merge (zipper) two lists
        ListNode *second = prev, *first = head;
        while (first && second) {
            ListNode *first_temp = first->next;
            ListNode *second_temp = second->next;
            first->next = second;
            second->next = first_temp;
            second = second_temp;
            first = first_temp;
        }
    }
};
