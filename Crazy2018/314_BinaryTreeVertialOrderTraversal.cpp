class Solution {
public:
    vector<vector<int>> verticalOrder(TreeNode* root) {
        vector<vector<int>> res;
        if(!root) return res;
        map<int, vector<int>> m;
        queue<pair<int, TreeNode*>> q;
        q.push({0, root});  // initialize pair
        while(!q.empty()){
            auto a = q.front(); q.pop();
            m[a.first].push_back(a.second->val); // no check if exist
            if(a.second->left) q.push({a.first-1, a.second->left});
            if(a.second->right)q.push({a.first+1, a.second->right});
        }
        // update res
        for(auto a: m){
            // MAP rather than unordered_map, thus ordering by generation resusing an increasing order
            res.push_back(a.second);
        }
        return res;
    }
};
