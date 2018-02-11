class Solution {
struct cmp{
    bool operator () (ListNode*a, ListNode*b){
        return a->val > b->val;
    }
};
    
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        // O(nlog(k))
        priority_queue<ListNode*, vector<ListNode*>, cmp> q;
        for(int i=0; i<lists.size();i++){
            if(lists[i]) q.push(lists[i]);
        }
        
        ListNode* res = NULL, *cur = NULL, *tmp=NULL;
        while(!q.empty()){
            tmp = q.top(); q.pop();
            if (!cur) res = tmp;
            else cur->next=tmp;
            cur = tmp;
            // O(log(k))
            if(tmp->next) q.push(tmp->next);
        }
        return res;
    }
};

// faster approach
class Solution {
public:
    ListNode *mergeKLists(vector<ListNode *> &lists) {
        // O(log(k)min(m,n))
        if (lists.size() == 0) return NULL;
        int n = lists.size();
        while (n > 1) {
            int k = (n + 1) / 2;
            for (int i = 0; i < n / 2; ++i) {
                lists[i] = mergeTwoLists(lists[i], lists[i + k]);
            }
            n = k;
        }
        return lists[0];
    }
    
    ListNode *mergeTwoLists(ListNode *l1, ListNode *l2) {
        // O(min(m, n))
        ListNode *head = new ListNode(-1);
        ListNode *cur = head;
        while (l1 && l2) {
            if (l1->val < l2->val) {
                cur->next = l1;
                l1 = l1->next;
            } else {
                cur->next = l2;
                l2 = l2->next;
            }
            cur = cur->next;
        }
        if (l1) cur->next = l1; // two lines can not be replaced by if ... else...
        if (l2) cur->next = l2; // for scenairo of [[],[]]
        return head->next;
    }
};