/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    bool isSameTree(TreeNode* p, TreeNode* q) {
        // check root existance => check val => check leaf
        if(!p &&!q)
            return true;
        if(!p && q || p &&!q )
            return false;
        if(p->val != q->val)
            return false;
        else
            return(isSameTree(p->left, q->left) && isSameTree(p->right, q->right));
        
    }
};