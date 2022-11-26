class Solution {
public:
    double champagneTower(int k, int r, int c) {
        vector<vector<double>> dp(101, vector<double>(101, 0.0));
        dp[0][0] = k;
        for(int i=0; i<100; i++){
            for(int j=0; j<=i; j++){
                if(dp[i][j] < 1) continue;
                
                dp[i+1][j] += (dp[i][j] - 1.0)/2.0;
                dp[i+1][j+1] += (dp[i][j] - 1.0)/2.0;        
            }
        }

        if(dp[r][c] >= 1) return 1;
        else if(dp[r][c] < 0) return 0;
        else return dp[r][c];
    }
};