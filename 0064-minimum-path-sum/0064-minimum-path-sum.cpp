class Solution {
public:
    int fn(int n, int m, vector<vector<int>> &dp, vector<vector<int>>& grid){
        if(n==1 && m ==1) return grid[n-1][m-1];
        if(n <= 0 || m <= 0) return 1e9;
        if(dp[n][m] != -1) return dp[n][m];
        
        int up = fn(n-1, m, dp, grid);
        int down = fn(n, m-1, dp, grid);
        
        return dp[n][m] = grid[n-1][m-1] + min(up, down);
    }
    
    int minPathSum(vector<vector<int>>& grid) {
        int n = grid.size(), m = grid[0].size();
        vector<vector<int>> dp(n+1, vector<int>(m+1, -1));
        return fn(n, m, dp, grid);
    }
};