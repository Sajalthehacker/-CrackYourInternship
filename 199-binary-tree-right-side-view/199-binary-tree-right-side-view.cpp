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
    vector<int> right;
    
    void dfs(TreeNode* root, int level){
        if(root == NULL) return;
        
        if(level == right.size()){
            right.push_back(root->val);
        }
        
        dfs(root->right, level+1);
        dfs(root->left, level+1);
    }
public:
    vector<int> rightSideView(TreeNode* root) {
        dfs(root, 0);
        return right;
    }
};