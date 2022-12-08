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
    vector<int> first, second;
    void dfs(TreeNode* root, bool flag){
        if(root == NULL) return;
        dfs(root -> left, flag);
        if(root -> left == NULL && root -> right == NULL) {
            if(flag) first.push_back(root -> val);
            else second.push_back(root -> val);
        }
        dfs(root -> right, flag);
    }
public:
    bool leafSimilar(TreeNode* root1, TreeNode* root2) {
        dfs(root1, true);
        dfs(root2, false);
        if(first.size() != second.size()) return false;
        for(int i=0; i<first.size(); i++){
            if(first[i] != second[i]) return false;
        }
        return true;
    }
};