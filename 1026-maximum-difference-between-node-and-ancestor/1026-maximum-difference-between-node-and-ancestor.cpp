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
    void dfs(TreeNode* root, int maxi, int mini, int &diff){
        if(root == NULL) return;
        // cout << root->val <<"  " << maxi << " " << mini << "--" << diff << endl;
        diff = max(diff, max(abs(maxi - root->val), abs(mini - root->val)));
        dfs(root -> left, max(maxi, root->val), min(mini, root->val), diff);                   dfs(root -> right, max(maxi, root->val), min(mini, root->val), diff);
    }
public:
    int maxAncestorDiff(TreeNode* root) {
        int maxi = root->val, mini = root->val, diff = 0;
        dfs(root, maxi, mini, diff);
        return diff;
    }
};