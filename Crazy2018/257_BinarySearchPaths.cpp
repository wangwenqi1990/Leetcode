/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    vector<string> binaryTreePaths(TreeNode* root) {
        vector<string> res;
        if(!root) return res;
        string out;
        dfs(root, res, out);
        return res;
    }
    
    void dfs(TreeNode* root, vector<string> &res, string out){
        // get a string when a node has no children
        out+=to_string(root->val);
        if(!root->left && !root->right){
            res.push_back(out);
        }   
        else{
            if(root->left)  dfs(root->left,res,out+"->");
            if(root->right) dfs(root->right,res,out+"->");
        }
    }
};

class Solution {
public:
    vector<string> binaryTreePaths(TreeNode* root) {
        // recursion
        vector<string> res;
        if(!root) return res;
        if(!root->left && !root->right){
            res.push_back(to_string(root->val));
            return res;   
        }
        
        vector<string> left = binaryTreePaths(root->left);
        vector<string> right= binaryTreePaths(root->right);
        left.insert(left.end(), right.begin(),right.end());
        for(auto &a : left)
            a = to_string(root->val)+"->"+a;
        return left;
    }
};