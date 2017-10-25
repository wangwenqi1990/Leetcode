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
    int closestValue(TreeNode* root, double target) {
        // res is the temperary closest value to the target from the tree
        // (1) update res using current root->val
        // (2) search next node
        int res = root -> val;
        while(root){
            if( abs(res - target) > abs(root->val -target))
                res = root -> val;
            
            if (root -> val == target)
                return root -> val;
            else if (root -> val < target)
                root = root -> right;
            else
                root = root -> left;
        }
        return res;
    }
};