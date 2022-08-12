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
private:
    TreeNode* dfs(TreeNode* root, TreeNode* p, TreeNode* q){
        if(root->val == p->val || root->val == q->val
          || (root->val <= max(p->val, q->val) && (root->val >= min(p->val, q->val)))) 
            return root;
        
        if(root->val < p->val && root->val < q->val) return dfs(root->right, p, q);
        else return dfs(root->left, p, q);
    }
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        return dfs(root, p, q);
    }
};