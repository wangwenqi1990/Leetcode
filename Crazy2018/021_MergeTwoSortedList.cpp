class Solution {
public:
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        // Computation: O(min(m,n)) Space: O(1)
        ListNode* dummy = new ListNode(0);
        ListNode* res = dummy;
        while(l1 && l2){
            if(l1->val <= l2->val){
                dummy->next = new ListNode(l1->val);
                l1=l1->next;
            }
                
            else{
                dummy->next = new ListNode(l2->val);
                l2=l2->next;
            }
            dummy = dummy->next;
        }
        if(l1)
            dummy->next = l1;
        else
            dummy->next = l2;
        
        return res->next;
    }
};