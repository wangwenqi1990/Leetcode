class Solution {
public:
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> res;
        if(!root) return res;
        queue<TreeNode*> q;
        q.push(root);
        while(!q.empty()){
            vector<int> r;
            int n = q.size();
            for(int i=0; i<n; ++i){
                TreeNode* tp = q.front(); q.pop();
                if(tp->left) q.push(tp->left);
                if(tp->right) q.push(tp->right);
                r.push_back(tp->val);
            }
            res.push_back(r);
        }
        return res;
    }
};
// This solution is slower
class Solution {
public:
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> res;
        BFS(root, 0, res);
        return res;
    }
    void BFS(TreeNode* root, int level, vector<vector<int>> &res){
        if(!root) return;
        if(res.size()==level) res.push_back({});
        res[level].push_back(root->val);
        if(root->left) BFS(root->left,level+1, res);
        if(root->right) BFS(root->right,level+1, res);
    }
};
