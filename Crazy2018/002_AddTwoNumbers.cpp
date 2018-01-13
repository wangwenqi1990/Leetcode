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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        // space O(1), computation O(max(m, n))
        ListNode *head = new ListNode(0);
        ListNode *res = head;
        int carry = 0;
        // 1. both exist
        while(l1 && l2){
            int tmp = l1->val + l2->val + carry;
            carry = tmp/10;
            res->next = new ListNode(tmp%10);
            res = res->next;
            l1 = l1->next;
            l2 = l2->next;
        }
        // 2. only one exist
        l1 = l1? l1 : l2;
        while(l1){
            int tmp = l1->val + carry;
            carry = tmp/10;
            res->next = new ListNode(tmp%10);
            res = res->next;
            l1 = l1->next;
        }
        // 3. check residual
        if(carry){
            res->next = new ListNode(1);
        }
        
        return head->next;        
    }
};

// easier to understand
class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode *res = new ListNode(0);
        ListNode *p = res;
        int carry = 0;
        while(l1 || l2){
            int tp= carry;
            if (l1){
                tp += l1->val;
                l1=l1->next;
            }
            if (l2){
                tp += l2->val;
                l2=l2->next;
            }
            p->next = new ListNode(tp % 10);
            p=p->next;
            carry = tp / 10;
        }
        if(carry) p->next = new ListNode(1);
        return res->next;
    }
};