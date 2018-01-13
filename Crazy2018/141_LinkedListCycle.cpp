/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    bool hasCycle(ListNode *head) {
        ListNode *slow = head;
        ListNode *fast = head;
        
        while(1){
            if(fast && fast->next)
                fast = fast->next->next;
            else
                return false;
            slow = slow->next;
            if(slow==fast)
                return true;
        }
        return true;
    }
};