class Solution {
public:
    // recursion
    // data type is long to avoid precision problem
    bool isValidBST1(TreeNode* root) {
        return isValidBST_range(root, LONG_MIN, LONG_MAX);
    }
    bool isValidBST_range(TreeNode* root, long mn, long mx){
        if(!root) return true;
        if(root->val<= mn ||root->val >= mx)   return false;
        return isValidBST_range(root->left, mn, root->val) && isValidBST_range(root->right, root->val, mx);
    }
}

class Solution {
public:
    // non-recursion solution    
    bool isValidBST(TreeNode* root) {
        if(!root) return true;
        stack<TreeNode*> s;
        while(root){
            s.push(root);
            root = root->left;
        }
        long tmp = LONG_MIN;
        while(!s.empty()){
            TreeNode* tp = s.top(); s.pop();
            if(tmp >= tp->val)  return false;
            tmp = tp->val;
            if(tp->right){
                tp = tp->right;
                while(tp){
                    s.push(tp);
                    tp=tp->left;
                }
            }
        }
        return true;
    }
};