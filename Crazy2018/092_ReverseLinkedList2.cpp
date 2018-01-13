class Solution {
public:
    ListNode* reverseBetween(ListNode* head, int m, int n) {
        // h->5-4->3->6(left)->7(right)->8
        ListNode *dummy = new ListNode(0);
        dummy->next = head;
        
        ListNode *left = dummy;
        for(int i=0;i<m-1;i++)
            left=left->next;
        
        ListNode *h = left;             // h    : the m-1 node
        left = left->next;              // left : the m node,
        ListNode *right = left->next;   // right: the m+1 node
        
        for(int i=m;i<n;i++){
            // left: the end of the reversed list
            // right = left->next
            left->next = right->next;
            right->next = h->next;
            h->next = right;
            right = left->next;
        }
        
        return dummy->next;
        
    }
};