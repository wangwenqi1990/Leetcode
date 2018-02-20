class Solution {
public:
    TreeNode* inorderSuccessor(TreeNode* root, TreeNode* p) {
        stack<TreeNode*> s;
        while(root){
            s.push(root);
            root=root->left;
        }
        while(!s.empty()){
            TreeNode* tp = s.top(); s.pop();
            if(tp->right){
                TreeNode* tmp = tp->right;
                while(tmp){
                    s.push(tmp);
                    tmp = tmp->left;
                }
            }
            if(tp == p){
                if(!s.empty())  return s.top();
                else            return nullptr;
            }
        }
        return nullptr;
    }
};