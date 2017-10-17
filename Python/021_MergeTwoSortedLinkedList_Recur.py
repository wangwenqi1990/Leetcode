# Definition for singly-linked list.
# class ListNode(object):
#     def __init__(self, x):
#         self.val = x
#         self.next = None

class Solution(object):
    def mergeTwoLists(self, l1, l2):
        """
        :type l1: ListNode
        :type l2: ListNode
        :rtype: ListNode
        """
        if not l1:
            return l2
        if not l2:
            return l1
        
        res = ListNode(0)
        tp  = res;
        
        while (l1 and l2):
            if l1.val<l2.val:
                tp.next = l1
                l1 = l1.next
            else:
                tp.next=l2
                l2=l2.next
            tp =tp.next
        
        if not l1:
            tp.next = l2
        else:
            tp.next = l1
        
        return res.next