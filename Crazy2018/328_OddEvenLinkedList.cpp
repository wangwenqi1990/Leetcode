class Solution {
public:
    ListNode* oddEvenList(ListNode* head) {
        if(!head)       return head;
        if(!head->next) return head;
        ListNode* res  = head;
        ListNode* left = head;
        ListNode* right= head->next;
        head = head->next->next;
        bool odd = true;
        while(head){
            // insert
            if(odd){
                ListNode*tp = left->next;
                ListNode*tp1= head->next;
                left->next = head;
                head->next = tp;
                left = left->next;
                head = tp1;
                odd = false;
            }
            // append
            else{
                right->next = head;
                right=right->next;
                head=head->next;
                odd=true;
            }
        }
        right->next = nullptr;
        return res;
    }
};