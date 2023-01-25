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
    int ans = 0;
    void dfs(TreeNode* root, int maxi){
        if(root == NULL) return ;
        // cout << root -> val << " " << maxi << endl;
        if(root -> val >= maxi) {
            ans++;
        }
        maxi = max(maxi, root -> val);
        dfs(root->left, maxi);
        dfs(root->right, maxi);
    }
public:
    int goodNodes(TreeNode* root) {
        dfs(root, -1e6);
        return ans;
    }
};