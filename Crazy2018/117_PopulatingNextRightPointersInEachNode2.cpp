/**
 * Definition for binary tree with next pointer.
 * struct TreeLinkNode {
 *  int val;
 *  TreeLinkNode *left, *right, *next;
 *  TreeLinkNode(int x) : val(x), left(NULL), right(NULL), next(NULL) {}
 * };
 */
class Solution {
public:
    // solution using just pointer
    // computation: O(n), space O(1)
    void connect(TreeLinkNode *root) {
        TreeLinkNode *dummy = new TreeLinkNode(0), *t = dummy;
        while(root){
            if(root->left)  {t->next = root->left;      t=t->next;}
            if(root->right) {t->next = root->right;     t=t->next;}
            root = root -> next;
            if(!root){
                root= dummy->next;
                dummy->next = NULL;
                t = dummy;
            }
        }
    }
};


// Solution with queue, computation: O(n) space: O(n)
class Solution {
public:
    void connect(TreeLinkNode *root) {
        queue<TreeLinkNode*> q;
        if(!root) return;
        q.push(root);
        while(!q.empty()){
            int n = q.size();
            for(int i=0; i< n; ++i){
                TreeLinkNode* tp = q.front(); q.pop();
                if(tp->left)  q.push(tp->left);
                if(tp->right) q.push(tp->right);
                if(i<n-1)   tp->next = q.front();
                else        tp->next = NULL;
            }
        }
    }
};
