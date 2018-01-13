class Solution {
public:
    ListNode* deleteDuplicates(ListNode* head) {
        // Computation: O(n) Space:O(1)
        // two pointers
        if(!head) return head;
        ListNode* left = head;
        ListNode* right= left->next;
        
        while(1){
            while(right && left->val==right->val)
                right = right->next;
            left->next = right;
            left = right;
            if(!right) break;       // stopping if right does not exist
            right= right->next;
        }
        return head;
    }
};