# Definition for singly-linked list.
# class ListNode(object):
#     def __init__(self, x):
#         self.val = x
#         self.next = None

class Solution(object):
    def reverseList(self, head):
        """
        :type head: ListNode
        :rtype: ListNode
        """
        pre = None;
        post = None;
        while(head):
            post = head.next;
            head.next = pre;
            pre = head;
            head = post;
        return pre