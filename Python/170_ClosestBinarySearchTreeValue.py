# Definition for a binary tree node.
# class TreeNode(object):
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution(object):
    def closestValue(self, root, target):
        """
        :type root: TreeNode
        :type target: float
        :rtype: int
        """
        res =  root.val
        while root:
            if abs(res-target) > abs(root.val -target):
                res = root.val 
            if root.val == target:
                return root.val
            elif root.val > target:
                root = root.left
            else
                root = root.right
        return res