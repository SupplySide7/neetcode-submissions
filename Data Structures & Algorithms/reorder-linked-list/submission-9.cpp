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
        ListNode *fast = head->next, *slow = head;
        while (fast && fast->next) {
            fast = fast->next->next;
            slow = slow->next;
        } // slow->next is the head of the second half of the list
        ListNode *curr = slow->next, *prev = nullptr;
        slow->next = nullptr;   // end the first half here
        while (curr) {
            ListNode *temp = curr->next;
            curr->next = prev;
            prev = curr;
            curr = temp;
        } // prev is the head of the reversed list
        ListNode *second = prev, *first = head;
        while (first && second) {
            ListNode *first_temp = first->next;
            first->next = second;
            ListNode *second_temp = second->next;
            second->next = first_temp;
            first = first_temp;
            second = second_temp;
        }
    }
};
