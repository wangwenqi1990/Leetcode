/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
 // recursion
class Solution {
public:
    bool findTarget(TreeNode* root, int k) {
        if( !root ) return false;
        unordered_set<int> s;
        return findtarget(root, k, s);
    }
    bool findtarget(TreeNode* root, int k, unordered_set<int> &s){
        if ( !root )    return false;
        
        if (s.count(k - root->val)>0)
            return true;
        else
            s.emplace(root->val);
        
        return findtarget(root->left, k, s) || findtarget(root->right, k, s);
    }
};

// Iteration
class Solution {
public:
    bool findTarget(TreeNode* root, int k) {
        if(!root) return false;
        stack<TreeNode*> s;
        unordered_set<int> st;
        s.push(root);
        
        while( !s.empty() ){
            TreeNode* tp = s.top();
            s.pop();
            if (st.count(k-tp->val)) 
                return true;
            else 
                st.emplace(tp->val);
            if(tp->left) s.push(tp->left);
            if(tp->right)s.push(tp->right);
        }
        return false;
    }
};