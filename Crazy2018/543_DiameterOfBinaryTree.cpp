class Solution {
public:
    int diameterOfBinaryTree(TreeNode* root) {
        if(!root) return 0;
        else
            return max(maxheight(root->left)+maxheight(root->right), 
                       max(diameterOfBinaryTree(root->left),diameterOfBinaryTree(root->right)));
        
    }
    
    int maxheight(TreeNode* root){
        if(!root) return 0;
        else return max(maxheight(root->left), maxheight(root->right))+1;
    }
};