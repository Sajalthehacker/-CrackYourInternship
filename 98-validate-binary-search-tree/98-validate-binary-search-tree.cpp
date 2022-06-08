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
    bool check(TreeNode* root, long long int left, long long int right){
        if(root == NULL) return true;
        if(root->val <= left || root->val >= right) return false;     
        
        return check(root->left, left, root->val) &&
               check(root->right, root->val, right);

    }
public:
    bool isValidBST(TreeNode* root) {
        long long int left = -2147483649, right = 21474836478;
        return check(root, left, right);
    }
};