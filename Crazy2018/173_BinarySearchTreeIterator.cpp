class BSTIterator {
public:
    // once call this, we initialize a stack
    BSTIterator(TreeNode *root) {
        while(root){
            s.push(root);
            root = root->left;
        }
    }

    /** @return whether we have a next smallest number */
    bool hasNext() {
        return !s.empty();
    }

    /** @return the next smallest number */
    int next() {
        // read the top node
        TreeNode* tp = s.top(); s.pop();
        int res = tp->val;
        // update stack
        if(tp->right){
            tp = tp->right;
            while(tp){
                s.push(tp);
                tp = tp->left;
            }
        }
        
        return res;   
    }
private:
    stack<TreeNode*> s;
};
