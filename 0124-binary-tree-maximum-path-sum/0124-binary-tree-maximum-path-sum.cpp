class Solution {
public:
    int maxPathSum(TreeNode* root) {
        int maxi = INT_MIN;
        dfs(root, maxi);
        return maxi;
    }

    int dfs(TreeNode* root, int &maxi){
        if(root == NULL) return 0;

        int leftSum = max(0, dfs(root -> left, maxi));
        int rightSum = max(0, dfs(root -> right, maxi));

        maxi = max(maxi , leftSum + rightSum + root -> val);

        return max(leftSum, rightSum) + root -> val;
    }
};