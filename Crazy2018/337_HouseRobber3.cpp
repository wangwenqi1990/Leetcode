class Solution {
public:
    int rob(TreeNode* root) {
        // dfs
        vector<int> res = dfs(root);
        return max(res[0], res[1]);
    }
    vector<int> dfs(TreeNode* root){
        // res[0]: root->val is not included
        // res[1]: root->val is included
        if(!root)   return vector<int>(2,0);
        vector<int> left = dfs(root->left);
        vector<int> right= dfs(root->right);
        vector<int> res(2,0);
        res[0]= max(left[0], left[1]) +max(right[0], right[1]); // root->val is not included
        res[1]=root->val+left[0]+right[0];
        return res;
    }
};