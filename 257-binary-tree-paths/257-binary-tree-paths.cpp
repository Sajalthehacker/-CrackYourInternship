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
    vector<string> paths;
    
    void dfs(TreeNode* root, string str){
        if(!root) return;
        
        if(root->left || root->right){
            str += to_string(root->val) + "->";
        }
        else{
            str += to_string(root->val);
            paths.push_back(str);
        }

        dfs(root->left, str);
        dfs(root->right, str);
        
    }
    
public:
    vector<string> binaryTreePaths(TreeNode* root) {
        string str = "";
        dfs(root, str);
        return paths;
    }
};