class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        // find size gap
        ListNode* pa = headA;   int sizeA = findSize(headA);
        ListNode* pb = headB;   int sizeB = findSize(headB);
        // adjust the gap
        int gap = sizeA - sizeB;
        if(gap>=0){
            for(int i=0;i<gap; i++)
                pa =pa->next;
        }
        else{
            for(int i=0;i<-gap; i++)
                pb =pb->next;
        }
        // compare the two lists
        while(pa && pa != pb){
            pa =pa->next;
            pb =pb->next;
        }
        return pa;
    }
    
    int findSize(ListNode* head){
        int res = 0;
        while(head){
            res++;
            head=head->next;
        }
        return res;        
    }
};