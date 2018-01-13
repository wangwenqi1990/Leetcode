class Solution {
public:
    ListNode* removeElements(ListNode* head, int val) {
        if(!head) return head;
        ListNode* dummy = new ListNode(0);
        dummy->next = head;
        ListNode *left = dummy;
        ListNode *right= head;
        
        while(right){
            if(right->val == val)
                right=right->next;
            else{
                left->next = right;
                left = right;
                right = right->next;
            } 
        }
        left->next = nullptr;
        return dummy->next;
    }
};