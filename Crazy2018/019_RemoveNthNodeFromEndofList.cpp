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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        // faster pointer and a slow pointer
        if(!head->next) return NULL;    // Important
        ListNode *l = head;
        ListNode *r = head;
        for(int i=0; i< n && r; i++){
            r= r->next;
        }
        if(!r) return head->next;
        while(r->next){
            r=r->next;
            l=l->next;
        }
        l->next=l->next->next;
        return head;
    }
};