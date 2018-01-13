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
    ListNode* partition(ListNode* head, int x) {
        // space: O(2n), computation O(n)
        ListNode *small = new ListNode(-1);
        ListNode *s = small;
        ListNode *big = new ListNode(-1);
        ListNode *b = big;
        ListNode *tp = head;
        
        while(tp){
            if(tp->val<x){
                s->next = new ListNode(tp->val);
                s = s->next;
            }
            else{
                b->next= new ListNode(tp->val);
                b=b->next;
            }
            tp=tp->next;
        }
        s->next = big->next;
        return small->next;
    }
};

class Solution {
public:
    ListNode* partition(ListNode* head, int x) {
        // space:O(1) computation: O(n) 
        ListNode *dummy = new ListNode(-1);
        dummy->next = head;
        ListNode *pre = dummy, *cur = head;
        // initialize and put all the front small nodes
        while(pre->next && pre->next->val < x)
            pre = pre->next;
        cur = pre;
        while(cur->next){
            if(cur->next->val<x){
                // insert a node
                ListNode*tmp = cur->next;
                cur->next = tmp->next;
                tmp->next = pre->next;
                pre->next = tmp;
                pre = pre->next;
            }
            else
                cur = cur->next;
        }
        return dummy->next; 
    }
};