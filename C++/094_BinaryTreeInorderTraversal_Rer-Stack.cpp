/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
// InorderTraversal(left -> root -> right)

// recursion
// computaiton: O(n)
// space: O(n)
class Solution {
public:
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> res;
        inorder(root, res);
        return res;
    }
    void inorder(TreeNode* root, vector<int> &res){
        if(!root)       return;
        if(root->left)  inorder(root-> left, res);  // if is for speeding up
        res.push_back(root -> val);
        if(root->right) inorder(root -> right, res);
    }
};

// stack
// Computation: O(n)
// Space: O(d)
class Solution {
public:
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> res;
        stack<TreeNode*> s;
        TreeNode *p = root;
        
        while( p || !s.empty()){
            // update s using p by addling all the left node into stack
            while(p){
                s.push(p);
                p = p->left;
            }
            // inorderTraversal
            p = s.top();
            s.pop();
            res.push_back(p->val);
            p = p->right;
        }
        
        return res;
    }
};