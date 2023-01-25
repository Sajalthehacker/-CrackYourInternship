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
    long long ans = 0, total = 0;
    int dfs(TreeNode* root){
        if(root == NULL) return 0;
        int currSum = root -> val;
        currSum += dfs(root->left) + dfs(root->right);
        ans = max(ans, currSum*(total - currSum));
        return currSum;
    }
    
    int maxProduct(TreeNode* root) {
        queue<TreeNode*> que;
        que.push(root);
        while(!que.empty()){
            TreeNode* it = que.front(); 
            que.pop();
            total += it -> val;
            if(it -> left) que.push(it -> left);
            if(it -> right) que.push(it -> right);
        }
        dfs(root);
        return ans%1000000007;
    }
};