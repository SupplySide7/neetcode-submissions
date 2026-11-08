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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode sentinel(0, head);
        ListNode *lead = head, *trail = &sentinel;
        for (int i = 0; i < n; ++i) lead = lead->next;
        while (lead) {
            lead = lead->next;
            trail = trail->next;
        }
        trail->next = trail->next->next;
        return sentinel.next;
    }
};
