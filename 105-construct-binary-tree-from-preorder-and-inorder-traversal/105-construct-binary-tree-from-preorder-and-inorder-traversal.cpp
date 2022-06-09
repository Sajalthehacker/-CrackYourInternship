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
    unordered_map<int, int> mpp;  
    TreeNode* buildTree(int inStart, int inEnd, int preStart, int preEnd, vector<int>& inorder, vector<int>& preorder){
        // Base Case
        if(preStart>preEnd || inStart>inEnd) return NULL; 
        
        
        TreeNode* root = new TreeNode(preorder[preStart]);
        
        int inRoot = mpp[root->val];
        int leftEle = inRoot - inStart;
        
        root -> left = buildTree(inStart, inRoot-1, preStart+1, preStart+leftEle, inorder, preorder);
        root -> right = buildTree(inRoot+1, inEnd, preStart+leftEle+1, preEnd, inorder, preorder);
        
        return root;
    }
    
public:
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        int n = inorder.size();
        
        for(int i=0; i<n; i++){
            mpp[inorder[i]] = i;
        }
        
        TreeNode* root = buildTree(0, n-1, 0, n-1, inorder, preorder);
        return root;
    }
};