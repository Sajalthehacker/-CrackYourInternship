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
    bool checkSubTrees(TreeNode* ls , TreeNode* rs){
        if(ls == NULL || rs == NULL) return ls == rs;
        return ls -> val == rs -> val &&
            checkSubTrees(ls -> left, rs ->right) &&
            checkSubTrees(ls -> right, rs ->left);
    }
public:
    bool isSymmetric(TreeNode* root) {
        if(root == NULL) return true;
        return checkSubTrees(root->left, root->right);
    }
};