class Solution {
public:
    int fn(int n, int m, string &text1, string &text2, vector<vector<int>> &dp){
        if(n<0 || m<0) return 0;
        if(dp[n][m] != -1) return dp[n][m];
        int lcs;
        if(text1[n] == text2[m]){
            lcs = 1 + fn(n-1, m-1, text1, text2, dp);
        }
        else {
            lcs = max(fn(n-1, m, text1, text2, dp) , fn(n, m-1, text1, text2, dp));
        }
        return dp[n][m] = lcs;
    }
    
    int longestCommonSubsequence(string text1, string text2) {
        int n = text1.size(), m = text2.size();
        vector<vector<int>> dp(n, vector<int>(m, -1));
        return fn(n-1, m-1, text1, text2, dp);
    }
};