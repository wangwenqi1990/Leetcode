class Solution {
public:
    vector<double> averageOfLevels(TreeNode* root) {
        vector<double> res;
        queue<TreeNode*> q;
        q.emplace(root);
        while(!q.empty()){
            double tp = 0, n = q.size();
            for(int i=0; i< n; i++){
                TreeNode* tmp = q.front(); q.pop();
                tp+=tmp->val;
                if(tmp->left)  q.emplace(tmp->left);
                if(tmp->right) q.emplace(tmp->right);
            }
            res.push_back(tp/n);
        }
        return res;
    }
};