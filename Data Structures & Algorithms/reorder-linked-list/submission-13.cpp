/** struct ListNode {int val; ListNode *next; ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}};*/
class Solution {
public:
    void reorderList(ListNode* head) {
        ListNode *lead = head->next, *trail = head;
        while (lead && lead->next) {
            lead = lead->next->next;
            trail = trail->next;
        }
        ListNode *curr = trail->next, *prev = nullptr;
        trail->next = nullptr; // end first list here
        while (curr) {
            ListNode *temp = curr->next;
            curr->next = prev; prev = curr; curr = temp;
        } ListNode *list2 = prev, *list1 = head;
        while (list1 && list2) {
            ListNode *list1_temp = list1->next;
            list1->next = list2;
            list1 = list1_temp;
            ListNode *list2_temp = list2->next;
            list2->next = list1;
            list2 = list2_temp;
        }
    }
};
