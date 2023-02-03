class Solution {
public:
    int dir[4][2] = {{1,0}, {-1,0}, {0,1}, {0,-1}};
    int dfs(int i, int j, vector<vector<int>>&dp, vector<vector<int>>& matrix){
        if(dp[i][j] != -1) return dp[i][j];
        int res = 1;
        for(auto it : dir){
            int ni = i+it[0], nj = j+it[1];
            if(ni<0 || nj<0 || ni == dp.size() || nj == dp[0].size()) continue;
            if(matrix[ni][nj] > matrix[i][j]) 
                res= max(res, 1 + dfs(ni, nj, dp, matrix));
        }
        return dp[i][j] = res; 
    }
    
    int longestIncreasingPath(vector<vector<int>>& matrix) {
        int n = matrix.size(), m = matrix[0].size();
        vector<vector<int>> dp(n, vector<int> (m, -1));
        int ans = 1;
        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                ans = max(ans, dfs(i, j, dp, matrix));
            }
        }
        return ans;
    }
};