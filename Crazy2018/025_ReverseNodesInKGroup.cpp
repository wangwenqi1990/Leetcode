class Solution {
public:
    ListNode* reverseKGroup(ListNode* head, int k) {
        ListNode *d = new ListNode(-1), *p=d, *c=d, *t = head;
        // c is the front pointer of the subgroup, c never changes
        // p is the dynamic pointer whose next is always the updated start of the subgroup
        d->next = head;
        int cnt = 0; while(t){++cnt; t=t->next;} // compute length
        while(cnt>=k){
            c = p->next;
            for(int i=0; i<k-1; ++i){
                t = c->next;
                c->next = t->next;
                t->next = p->next;
                p->next = t;
            }
            p= c;
            cnt-=k;
        }
        return d->next;
    }
};
