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
    bool isCompleteTree(TreeNode* root) {
        // TreeNode* temp = new TreeNode*(-1);
        queue<TreeNode*> que;
        que.push(root);
        while(!que.empty()){
            TreeNode* curr = que.front();
            que.pop();
            if(curr) {
                que.push(curr -> left);
                que.push(curr -> right);
            }
            else {
                while(!que.empty()){
                    if(que.front() != NULL) return false;
                    que.pop();
                }
            }
        }
        return true;
    }
};