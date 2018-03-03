class Solution1 {
public:
    bool isValidBST(TreeNode* root) {
        return isValidBST(root, LONG_MIN, LONG_MAX);
    }
    bool isValidBST(TreeNode* root, long l, long r){
        // top-down search
        if(!root)   return true;
        if(root->val <= l || root->val >= r) return false;
        return isValidBST(root->left, l, root->val) && isValidBST(root->right, root->val, r);
    }
};

class Solution2 {
public:
    bool isValidBST(TreeNode* root) {
        TreeNode* prev = NULL;
        return validate(root, prev);
    }
    bool validate(TreeNode* node, TreeNode* &prev) {
        if (node == NULL) return true;
        if (!validate(node->left, prev)) return false;
        if (prev != NULL && prev->val >= node->val) return false;
        prev = node;
        return validate(node->right, prev);
    }
};