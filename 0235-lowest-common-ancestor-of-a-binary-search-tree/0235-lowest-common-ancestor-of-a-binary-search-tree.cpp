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
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        // Base Case
        if(root == NULL) return NULL;
        int mini = min(p->val, q->val), maxi = max(p->val, q->val);
        
        if(root -> val >= mini && root -> val <= maxi) return root; // split
        else if(root -> val > maxi) 
            return lowestCommonAncestor(root -> left, p, q);    // go to left subtree
        else
            return lowestCommonAncestor(root -> right, p, q);   // go to right subtree
    }
};