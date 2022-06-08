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
    vector<vector<int>> levelOrder(TreeNode* root) {
        
        vector<vector<int>> ans;
        if(root == NULL) return ans;
        
        queue<TreeNode*> que;
        que.push(root);
        
        while(!que.empty()){
            vector<int> level;
            int size = que.size();
            for(int i=0; i<size; i++){
                TreeNode* temp = que.front();
                que.pop();
                level.push_back(temp -> val);
                if(temp->left) que.push(temp->left);
                if(temp->right) que.push(temp->right);
            }
            ans.push_back(level);
        }
        return ans;
    }
};