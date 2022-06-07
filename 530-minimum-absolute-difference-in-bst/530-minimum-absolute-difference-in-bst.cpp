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
    void dfs(TreeNode* root, int &prev, int &diff){
        
        if(!root) return;
        
        dfs(root->left, prev, diff);
        // cout<< root->val <<" " <<prev<<" "<<diff<<endl;
        if(prev != -1){
            diff = min(diff, root->val - prev);
        }
        prev = root->val;  
        dfs(root->right, prev, diff);
    }
public:
    int getMinimumDifference(TreeNode* root) {
        int diff = 100000;
        int prev = -1;
        dfs(root, prev, diff);
        return diff;
    }
};