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
    int sumEvenGrandparent(TreeNode* root, int p = -1, int gp = -1) {
        if(root == NULL) return 0;
        int sum = 0;
        if(gp%2 == 0) sum += root -> val;
        
        int ls = sumEvenGrandparent(root->left, root->val, p);
        int rs = sumEvenGrandparent(root->right, root->val, p);
        return sum + ls + rs;
    }
};