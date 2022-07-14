class Solution {
private:
    int fn(int i, int j, int &n, vector<vector<int>>& dp, vector<vector<int>>& tri){
        if(i >= n) return 0;
        if(i == n-1) return tri[i][j];
        if(dp[i][j] != -1) return dp[i][j];
        
        return dp[i][j] = tri[i][j] + min(fn(i+1, j, n, dp, tri) , fn(i+1, j+1, n, dp, tri));
    }
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        int n = triangle.size();
        vector<vector<int>> dp(n, vector<int>(n, -1));
        return fn(0, 0, n, dp, triangle);
    }
};