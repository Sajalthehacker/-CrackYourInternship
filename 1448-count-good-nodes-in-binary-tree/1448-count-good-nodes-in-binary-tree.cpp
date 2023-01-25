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
    int goodNodes(TreeNode* root, int maxi = INT_MIN) {
        int ans = 0;
        if(root == NULL) return 0;
        if(root->val >= maxi){
            maxi = max(maxi, root->val);
            ans++;
        }
        ans += goodNodes(root->left, maxi) + goodNodes(root->right, maxi);
        return ans;
    }
};