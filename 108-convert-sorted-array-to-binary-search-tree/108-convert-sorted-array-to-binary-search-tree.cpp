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
    TreeNode* createBST(int l, int r, vector<int> &nums){
        // Base Case
        if(l > r) return NULL;
        int mid = l + (r - l)/2;
        
        // As this is a BST, We assume middle ele as a root, 
        // Left subArray as left sub-tree, right subarray as Right sun-tree
        TreeNode* root = new TreeNode(nums[mid]);
        root -> left = createBST(l, mid-1, nums);
        root -> right = createBST(mid+1, r, nums);
        
        // return the root
        return root;
    }
public:
    TreeNode* sortedArrayToBST(vector<int>& nums) {
        int n = nums.size()-1;
        return createBST(0, n, nums);
    }
};