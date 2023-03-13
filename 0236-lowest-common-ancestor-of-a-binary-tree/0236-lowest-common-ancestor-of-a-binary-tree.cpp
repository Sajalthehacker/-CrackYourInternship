class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if(root == NULL) return NULL;
        if(root == p || root == q) return root; //even if other is left or right, lca is present node

        TreeNode* left = lowestCommonAncestor(root->left, p, q);
        TreeNode* right = lowestCommonAncestor(root->right, p, q);

        if(left == NULL) return right; //none of elements are present in left
        if(right == NULL) return left; //none of elements are present in right

        return root; // each of elements present in left and right subtrees
    }
};