# Definition for singly-linked list.
# class ListNode(object):
#     def __init__(self, x):
#         self.val = x
#         self.next = None

import heapq
class Solution(object):
    def mergeKLists(self, lists):
        """
        :type lists: List[ListNode]
        :rtype: ListNode
        """
        q = []
        for l in lists:
            if l:
                heapq.heappush(q, (l.val, l))
        
        res = ListNode(0)
        tmp = res
        
        while q:
            qtop = heapq.heappop(q)[1]
            tmp.next = qtop
            tmp = tmp.next
            if qtop.next:
                heapq.heappush(q, (qtop.next.val, qtop.next))
        
        return res.next