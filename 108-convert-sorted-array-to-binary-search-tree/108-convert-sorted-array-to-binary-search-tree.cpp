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
    TreeNode* createBST(vector<int> &nums, int start, int end){
        if(start > end){
            return NULL;
        }
        int mid = (start+end) >> 1;
        
        TreeNode* root = new TreeNode(nums[mid]);
        root->left = createBST(nums, start, mid-1);
        root->right = createBST(nums, mid+1, end);
        
        return root;
    }
public:
    TreeNode* sortedArrayToBST(vector<int>& nums) {
        if(nums.size() == 0) return NULL; // Base Case
        return createBST(nums, 0, nums.size()-1);
    }
};