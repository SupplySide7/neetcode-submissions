/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val; ListNode *next; ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}};*/
class Solution {
public:
    void reorderList(ListNode* head) {
        ListNode *fast = head->next, *slow = head;
        while (fast && fast->next) {
            fast = fast->next->next;
            slow = slow->next;
        }
        ListNode *curr = slow->next, *prev = nullptr;
        slow->next = nullptr; // end first half list here
        while (curr) {
            ListNode *temp = curr->next;
            curr->next = prev;
            prev = curr;
            curr = temp;
        }
        ListNode *list1 = head, *list2 = prev;
        while (list1 && list2) {
            ListNode *list1_temp = list1->next;
            list1->next = list2;
            list1 = list1_temp;
            ListNode *list2_temp = list2->next;
            list2->next = list1;
            list2 =list2_temp;
        }
    }
};
