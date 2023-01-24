/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:


    TreeNode* pruneTree(TreeNode* root) {
        if(root == NULL) return root;
        
        TreeNode* ll = pruneTree(root->left);
        TreeNode* rr = pruneTree(root->right);
        
        if(ll || rr || root -> val == 1){
            if(ll == NULL) root -> left = NULL;
            if(rr == NULL) root -> right = NULL;
            return root;
        }
        return NULL;

    }
};