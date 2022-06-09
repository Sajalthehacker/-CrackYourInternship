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
    int pathSum(TreeNode* root, int targetSum) {
        if(root == NULL) return 0;
        dfsSum(root, targetSum, 0);
        pathSum(root->left, targetSum);
        pathSum(root->right, targetSum);

        return ans;
    }
private:
    int ans = 0;
    const int N = 1e9;
    void dfsSum(TreeNode* root, int sum, int curSum){
        if(root == NULL) return;
        curSum = ((curSum%N) + (root->val%N) % N);
        if(curSum == sum) ans++;
        
        dfsSum(root->left, sum, curSum);
        dfsSum(root->right, sum, curSum);
    }
};