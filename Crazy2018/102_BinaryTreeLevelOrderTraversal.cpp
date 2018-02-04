class Solution {
public:
    vector<vector<int>> levelOrder(TreeNode* root) {
        // queue
        vector<vector<int>> res;
        if(!root) return res;
        queue<TreeNode*> q;
        q.emplace(root);
        
        while(!q.empty()){
            int q_size = q.size();
            vector<int> layer;
            for(int i=0; i<q_size; i++){
                TreeNode* tp = q.front(); q.pop();
                layer.push_back(tp->val);
                if(tp->left) q.emplace(tp->left);
                if(tp->right) q.emplace(tp->right);
            }
            res.push_back(layer);
        }
        return res;
    }
};

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