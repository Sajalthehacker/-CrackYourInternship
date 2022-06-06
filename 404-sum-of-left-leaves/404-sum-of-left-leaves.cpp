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
    int sum = 0;
    void dfs(TreeNode* root, int dir){
        if(root == NULL) return;
        
        if(root->left==NULL && root->right==NULL && dir == 0){
          sum += root->val;
          return;
        }
        dfs(root->left, 0);
        dfs(root->right, 1);

    }
public:
    int sumOfLeftLeaves(TreeNode* root) {
        if(root == NULL) return 0;
        
        dfs(root, -1);
        return sum;
    }
};