/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
/*
Computation: O(nlog(k))
Space: O(k)
*/
struct cmp{
    bool operator()(ListNode*a, ListNode*b){
        return a->val < b->val;
    }  
};

class Solution {
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        priority_queue<ListNode*, vector<ListNode*>, cmp> q;
        
        for(int i=0; i< lists.size(); i++){
            if(lists[i]) q.push(lists[i]);
        }
        // qtop is the pointer to the top of the prioity queue
        // res is the pointer to be returned
        // tmp is the pointer helping to build the link
        ListNode *qtop=NULL, *res = NULL, *tmp=NULL; 
        while( !q.empty()){
            // get the top node
            qtop = q.top(); q.pop();
            
            // update link
            if(!tmp) 
                res = qtop;
            else 
                tmp->next =qtop;
            tmp = qtop;
            
            // update the queue
            if(qtop->next)
                q.push(qtop->next);
        }
        return res;
    }
};