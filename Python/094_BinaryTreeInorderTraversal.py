# stack
class Solution(object):
    def inorderTraversal_stack(self, root):
        s =[]
        res =[]
        p = root;
        while p or s:
            while p:
                s.append(p);
                p=p.left
            p = s.pop()
            res.append(p.val)
            p = p.right
        return res
# recursion
class Solution(object):
    def inorderTraversal(self, root):
        """
        :type root: TreeNode
        :rtype: List[int]
        """
        res =[]
        self.inorder(root, res)
        return res
        
        
    def inorder(self, root, res):
        if not root:
            return 
        if root.left: 
            self.inorder(root.left, res)
        res.append(root.val)
        if root.right:
            self.inorder(root.right, res)