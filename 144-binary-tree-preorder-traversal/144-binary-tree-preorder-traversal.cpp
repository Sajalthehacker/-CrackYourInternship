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
    vector<int> preorderTraversal(TreeNode* root) {
        // Iterative
        stack<TreeNode*> stt;
        vector<int> pre;
        if(root == NULL) return pre;
        stt.push(root);
        while(!stt.empty()){
            TreeNode* curr = stt.top();
            stt.pop();
            pre.push_back(curr->val);
            if(curr->right != NULL) stt.push(curr->right);
            if(curr->left != NULL) stt.push(curr->left);
        }
        return pre;
    }
};