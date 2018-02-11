class Solution {
public:
    ListNode* reverseKGroup(ListNode* head, int k) {
        // computation: O(n)
        // *pre: the end node of the previous k reversed node
        // *cur: the start node of the next K reversed node
        // *dummy: the node to be returned
        // *t:     the node to be revered next in the k nodes
        ListNode *dummy = new ListNode(-1), *pre = dummy, *cur = pre;
        dummy->next = head;
        int num = 0;while (cur = cur->next) ++num;// compute the length, O(n)
        while (num >= k) {
            cur = pre->next;
            for (int i = 1; i < k; ++i) {
                ListNode *t = cur->next;
                cur->next = t->next;
                t->next = pre->next;
                pre->next = t;
            }
            pre = cur;
            num -= k;
        }
        return dummy->next;
    }
};