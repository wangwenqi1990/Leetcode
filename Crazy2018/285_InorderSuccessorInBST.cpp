class Solution {
public:
    TreeNode* inorderSuccessor(TreeNode* root, TreeNode* p) {
        // stack to implement inorderSucessor
        stack<TreeNode*> s;
        while(root){
            s.push(root);
            root= root->left;
        }
        while( !s.empty()){
            TreeNode* t = s.top(); s.pop();
            TreeNode* tp = t->right;
            while(tp){
                s.push(tp);
                tp = tp->left;
            }
            if(t==p) break;
        }
        return !s.empty() ? s.top() : nullptr;
    }
};
