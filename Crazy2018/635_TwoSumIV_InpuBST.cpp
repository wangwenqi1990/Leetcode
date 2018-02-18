class Solution {
public:
    bool findTarget(TreeNode* root, int k) {
        unordered_set<int> s;
        queue<TreeNode*> q{{root}};
        while(!q.empty()){
            TreeNode *tp = q.front();q.pop();
            if(s.count(k-tp->val)) return true;
            s.insert(tp->val);
            if(tp->left) q.push(tp->left);
            if(tp->right) q.push(tp->right);
        }
        return false;
    }
};