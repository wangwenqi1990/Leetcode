class Solution {
public:
    int sumOfLeftLeaves(TreeNode* root) {
        //recursion
        int res = 0;
        if(!root) return res;
        if(root->left){
            if(!root->left->left && !root->left->right)
                res += root->left->val;
            else
                res += sumOfLeftLeaves(root->left);
        }
        if(root->right){
            res += sumOfLeftLeaves(root->right);
        }
        return res;
    }
};