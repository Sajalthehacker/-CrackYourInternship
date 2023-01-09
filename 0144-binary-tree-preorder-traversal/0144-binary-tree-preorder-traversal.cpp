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
        vector<int> preOrder;
        if(root == NULL) return preOrder; // Null Tree's Edge case

        stack<TreeNode*> stt;
        
        stt.push(root);
        while(!stt.empty()){
            TreeNode* curr = stt.top();
            stt.pop();
            preOrder.push_back(curr -> val);
            // actual order is left and right
            // but as we are operating on stack, we pushed these in reverse order
            if(curr -> right != NULL) stt.push(curr -> right);
            if(curr -> left != NULL) stt.push(curr -> left);
        }
        return preOrder;
    }
};