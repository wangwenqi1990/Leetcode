class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        // compuation: O(n) space: O(1)
        // eg: dummy-> null
        //     1(head)->2(tp=head->next)->3->...
        ListNode* dummy = new ListNode(0);
        
        while(head){
            ListNode *tp = head->next;
            head->next = dummy->next;
            dummy->next = head;
            head = tp;
        }
        
        return dummy->next;
    }
};