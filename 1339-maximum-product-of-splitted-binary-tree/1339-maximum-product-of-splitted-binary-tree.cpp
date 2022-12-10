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
        
        // Idea : ans is max of all subTreeSum*(total - subTreeSum)
        // we did post order because, in that case
        // leafs are done first and root is added, which is indirectle subtree sum
        
        long long currSum = dfs(root -> left) + dfs(root -> right) + root -> val;
        ans = max(ans, currSum*(fullSum - currSum));
        return currSum;
    }
public:
    int maxProduct(TreeNode* root) {
        fullSum = dfs(root); // It'll get the sum of toatal tree

        dfs(root); //  in the next traversal, we calculate sum of subrees
        return ans%mod;
    }
};