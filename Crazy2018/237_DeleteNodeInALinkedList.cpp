class Solution {
public:
    void deleteNode(ListNode* node) {
        if(!node || !node->next)
            return;
        
        ListNode *TBD = node->next;
        node->val =TBD->val;
        node->next = TBD->next;
        delete TBD;
    }
};