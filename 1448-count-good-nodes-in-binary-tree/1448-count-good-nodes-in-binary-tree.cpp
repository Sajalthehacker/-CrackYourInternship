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
// private:
//     int goodCnt = 0;
    
//     void dfs(TreeNode* root, int currMax){
//         if(root == NULL) return;
        
//         if(root->val >= currMax){
//             currMax = root->val;
//             goodCnt++;
//         }
//         dfs(root->left, currMax);
//         dfs(root->right, currMax);
//     }
    
public:
    int goodNodes(TreeNode* root, int curMax = INT_MIN) {
        int ans = 0;
        if(root == NULL) return 0;
        
        if(root -> val >= curMax){
            curMax = root -> val;
            ans++;
        }
        ans += goodNodes(root -> left, curMax) + goodNodes(root -> right, curMax);
        return ans;
    }
};