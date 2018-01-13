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
    ListNode *detectCycle(ListNode *head) {
        // meet condition: (2l-m)%r == (l-m)%r, indicating l%r=0;
        // Thus set the slow point to the begining and move the faster pointer by 1 can find the starting nodes.
        ListNode *s = head, *f = head;
        while(f && f->next){
            s=s->next;
            f=f->next->next;
            // find a cycle
            if(s==f){
                s = head;
                while(s!=f){
                    s=s->next;
                    f=f->next;
                }
                return s;
            }
        }
        return nullptr;
    }
};