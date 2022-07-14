class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
        // Iterative Approach 
        // TC : O(n*m) && SC : O(n*m)
        int n = grid.size(), m = grid[0].size();
        
        // State : dp(i, j) -> min path-sum from (i, j) to (n, m);
        vector<vector<int>> dp(n+1, vector<int>(m+1, 0));
        dp[n-1][m-1] = grid[n-1][m-1];
        for(int i=n-1; i>=0; i--){
            for(int j=m-1; j>=0; j--){
                if(i == n-1 && j == m-1) dp[i][j] = grid[i][j]; // Edgecase - already in final block
                // In bottom line , we can only go right (i, j) -> (i, j+1)
                else if(i == n-1) dp[i][j] = grid[i][j] + dp[i][j+1]; 
                // In right-most column , we can only go down (i, j) -> (i+1, j)
                else if(j == m-1) dp[i][j] = grid[i][j] + dp[i+1][j];
                else{
                    dp[i][j] = grid[i][j] + min(dp[i+1][j], dp[i][j+1]);
                }
            }
        }
        return dp[0][0];
    }
};