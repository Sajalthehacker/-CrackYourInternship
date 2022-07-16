class Solution {
public:
    long long int mod = 1e9 + 7;
        
    int findPaths (int m, int n, int maxMove, int startRow, int startColumn) {
        vector<vector<vector<int>>> dp(m+1, vector<vector<int>>(n+1, vector<int>(maxMove+1, -1)));
        
        return fn(startRow, startColumn, m, n, maxMove, dp);
    }
    
    long long int fn(int i, int j, int m, int n, int maxMove, vector<vector<vector<int>>> &dp){
        if(maxMove < 0) return 0;
        if(i < 0 || i >= m || j < 0 || j >= n) return 1;
        if(dp[i][j][maxMove] != -1) return dp[i][j][maxMove];
        
        long long left = fn(i, j-1, m, n, maxMove-1, dp);
        long long right = fn(i, j+1, m, n, maxMove-1, dp);
        long long down = fn(i+1, j, m, n, maxMove-1, dp);
        long long up = fn(i-1, j, m, n, maxMove-1, dp);
        
        return dp[i][j][maxMove] = (int)(((left % mod) +(right % mod) +(up % mod) +(down % mod)) % mod);

    }
};