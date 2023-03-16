class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if(root == p || root == q) return root;
        if(root == NULL) {
            // there isn' a niode in that partcular sub tree
            return NULL;
        }
        
        TreeNode* left = lowestCommonAncestor(root->left, p, q);
        TreeNode* right = lowestCommonAncestor(root->right, p, q);
        
        if(left == NULL){
            // p, q arent present in left, so they would be in  right
            return right;
        }
        else if(right == NULL) 
            return left;
        else return root;
        
    }
};