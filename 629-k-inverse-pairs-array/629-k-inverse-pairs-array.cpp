class Solution {
public:
    int kInversePairs(int n, int K) {
        
        // link : https://leetcode.com/problems/k-inverse-pairs-array/discuss/2293243/DP-explained-with-figures-Python
        int mod = 1000000007;
       vector<vector<int>> dp(n+1,vector<int>(K+1,0));
        dp[0][0]=0;
        for(int i=1;i<=K;i++){
            dp[1][i]=0;
        }
        for(int i=1;i<=n;i++){
            dp[i][0]=1;
        }
        
        for(int i=2;i<=n;i++){
            for(int j=1;j<=K;j++){
                dp[i][j]=(dp[i-1][j]+dp[i][j-1])%mod;
                if(j-i>=0){
                    dp[i][j]=(dp[i][j]-dp[i-1][j-i]+mod)%mod;
                }
            }         
        }
        return dp[n][K]; 
    }
};