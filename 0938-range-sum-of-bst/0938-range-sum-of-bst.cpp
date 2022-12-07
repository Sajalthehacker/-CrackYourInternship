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
private:
    void dfs(TreeNode* root, int low, int high, int &sum){
        // Base Case
        if(!root) return;
        
        // Explore left of node, Only if the val id greater than low, 
        //else all those will be smaller than val and there'll be no use in traversing them 
        if(root->val > low) dfs(root->left, low, high, sum);
        if(root->val >= low && root->val <= high) 
            sum += root->val;
        // Only explore the right if val is less than high
        if(root->val < high) dfs(root->right, low, high, sum);
    }
public:
    int rangeSumBST(TreeNode* root, int low, int high) {
        int sum = 0;
        dfs(root, low, high, sum);
        return sum;
    }
};