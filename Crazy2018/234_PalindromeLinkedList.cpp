class Solution {
public:
    bool isPalindrome(ListNode* head) {
        ListNode* dummy =new ListNode(0);
        dummy->next = head;
        ListNode *slow = dummy;
        ListNode *fast = dummy;
        
        // find the start nodes for the Palindrome
        while(fast->next && fast->next->next){
            slow = slow->next;
            fast = fast->next->next;
        }
        
        ListNode *h = nullptr;
        if(!fast->next)
            h = slow->next;
        else
            h = slow->next->next;
        
        // reverse linked list from h to the end
        ListNode *dummy2 = new ListNode(0); // DO NOT put the dummy2->next = h
        while(h){
            ListNode* tp = h->next;
            h->next = dummy2->next;
            dummy2->next = h;
            h = tp;
        }
        dummy2 =dummy2->next;
        
        // entry-wise check
        while(dummy2){
            if(dummy2->val == head->val){
                dummy2=dummy2->next;
                head = head->next;
            }
            else
                break;
        }
        return !dummy2 ? true : false;
    }
};