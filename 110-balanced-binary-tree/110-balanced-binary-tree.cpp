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
    int maxD(TreeNode* root){
        if(root == NULL) return 0; // Base Case
        
        // Checking for left subtree
        int lh = maxD(root->left);
        if(lh == -1) return -1;
        
        // Checking for Right subtree
        int rh = maxD(root->right);
        if(rh == -1) return -1;
        
        if(abs(lh-rh) > 1) return -1;
        
        return 1 + max(lh, rh);
    } 
public:
    bool isBalanced(TreeNode* root) {
        if(maxD(root) == -1) return false;
        else return true; 
    }
};