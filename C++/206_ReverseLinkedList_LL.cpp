#include "package_wwq.cpp"

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

// 1->  2 ->    3 -> null
//pre   head    post
/*
Computational complexity: O(n)
Space complexity: O(1)
*/
class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        ListNode* pre  = NULL;
        ListNode* post = NULL;
        while(head){
            post = head->next;
            head->next = pre;
            pre = head;
            head = post;   
        }
        return pre;
    }
};

void printLinkedList(ListNode *head){
    while(head){
        cout << head-> val << ',';
        head = head -> next;
    }
    cout << endl;
}

int main(){
    // generate a linked list
    ListNode *n1 = new ListNode(1);
    ListNode *n2 = new ListNode(2);
    ListNode *n3 = new ListNode(3);
    n1->next = n2;
    n2->next = n3;

    // print linked list
    ListNode *head = n1;
    printLinkedList(head);
    
    // reverse the linked list and print
    ListNode *head2 = Solution().reverseList(head);
    printLinkedList(head2);
}