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
    ListNode* rotateRight(ListNode* head, int k) {
        int len =0;
        ListNode* tmp= head;
        while(tmp){
            len++;
            tmp = tmp->next;
        }
        // (1) check empty
        if(len==0) return head;     
        k = k % len;
        
        // (2) set left and right pointer
        ListNode *left = head;
        ListNode *right= head;
        for(int i=0; i<k; i++){
            right=right->next;
        }
        while(right->next){
            left=left->next;
            right=right->next;
        }
        
        // (3) return results
        right->next = head;
        ListNode *res = left->next? left->next:head;
        left->next = NULL;
        return res;
    }
};