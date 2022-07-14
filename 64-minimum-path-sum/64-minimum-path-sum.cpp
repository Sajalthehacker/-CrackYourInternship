class Solution {
private:
    int fn(int i, int j, vector<vector<int>> &dp, vector<vector<int>>& grid){
        if(i==0 && j==0) return grid[0][0];
        if(j == 0) return grid[i][j] + fn(i-1, j, dp, grid);
        if(i == 0) return grid[i][j] + fn(i, j-1, dp, grid);
        
        if(dp[i][j] != -1) return dp[i][j];
        
        return dp[i][j] = grid[i][j] + min(fn(i-1, j, dp, grid) , fn(i, j-1, dp, grid));
    }
public:
    int minPathSum(vector<vector<int>>& grid) {
        // Recursive Approach 
        // TC : O(n*m) && SC : O(n*m) + O(n+m-2)-> extra space for recursion call stack
        int n = grid.size(), m = grid[0].size();
        vector<vector<int>> dp(n+1, vector<int>(m+1, -1));
        return fn(n-1, m-1, dp, grid);
    }
};