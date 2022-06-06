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
    int dfs(TreeNode* root, int &diameter){
        if(root == NULL) return 0; // Base Case
        
        int lh = dfs(root->left, diameter);
        int rh = dfs(root->right, diameter);

        diameter = max(diameter, lh+rh);
        return 1 + max(lh, rh);
    }
public:
    int diameterOfBinaryTree(TreeNode* root) {
        int diameter = 0;
        int temp = dfs(root, diameter);
        return diameter;
    }
};