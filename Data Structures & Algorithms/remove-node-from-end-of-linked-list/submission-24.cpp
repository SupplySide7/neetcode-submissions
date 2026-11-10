/** struct ListNode {int val; ListNode *next; ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}};*/
class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode pre_head(0, head), *trail = &pre_head, *lead = head;
        for (int i = 0; i < n; ++i) lead = lead->next;
        while (lead) { // want to end at lead->next = nullptr
            lead = lead->next;
            trail = trail->next;
        } trail->next = trail->next->next;
        return pre_head.next;
    }
};
