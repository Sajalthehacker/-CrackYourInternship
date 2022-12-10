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
    long long ans = 0, fullSum = 0, mod = 1e9 + 7;
    int dfs(TreeNode* root){
        if(root == NULL) return 0;
        
        long long currSum = dfs(root -> left) + dfs(root -> right) + root -> val;
        ans = max(ans, currSum*(fullSum - currSum));
        return currSum;
    }
public:
    int maxProduct(TreeNode* root) {
        fullSum = dfs(root);

        dfs(root);
        return ans%mod;
    }
};