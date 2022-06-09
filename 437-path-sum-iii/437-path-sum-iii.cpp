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
    int pathSum(TreeNode* root, int targetSum) {
        if(root == NULL) return 0;
        unordered_map<int, int> mpp;
        int pref = 0;
        mpp[0] = 1;
        dfsSum(root, targetSum, 0, mpp);

        return ans;
    }
private:
    int ans = 0;
    const int N = 1e9;
    
    void dfsSum(TreeNode* root, int sum, int curSum, unordered_map<int, int> &mpp){
        if(root == NULL) return;
        
        // curSum += root->val;
        // Modular Addition, as the sum is btween -1000->1000, we can just use MOD 
        curSum = ((curSum%N) + (root->val%N) % N);
        if(mpp.find(curSum-sum) != mpp.end()){
            ans += mpp[curSum-sum];
        }
        mpp[curSum]++;
        dfsSum(root->left, sum, curSum, mpp);
        dfsSum(root->right, sum, curSum, mpp);
        mpp[curSum]--;
        return;
    }
};