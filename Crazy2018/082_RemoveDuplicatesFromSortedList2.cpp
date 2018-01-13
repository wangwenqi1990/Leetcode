class Solution {
public:
    ListNode* deleteDuplicates(ListNode* head) {
        // computation: O(n) space: O(1)
        ListNode* dummy = new ListNode(0);
        ListNode* tp = dummy;
        if(!head) return head;
        ListNode* left = head;
        ListNode* right= head->next;
        
        while(1){
            while(right && left->val == right->val)
                right= right->next;
            // update only if left->next == right
            if(left->next == right){                
                tp-> next = left;
                tp = tp->next;
            }
            if(!right) break;
            left = right;
            right=left->next;
        }
        if(tp) tp->next = NULL;     // check if the end list are the same
        return dummy->next;
    }
};