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
    vector<int> inorderTraversal(TreeNode* root) {
        // Iterative
        stack<TreeNode*> stt;
        vector<int> inorder;
        
        while(true){
            if(root != NULL){
                stt.push(root);
                root = root -> left;
            }
            else{
                if(stt.empty()) break;
                root = stt.top();
                inorder.push_back(root->val);
                root = root->right;
                stt.pop();
            }
        }
        
        return inorder;
    }
};