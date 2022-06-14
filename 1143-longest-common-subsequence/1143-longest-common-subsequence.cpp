class Solution {
public:
    int longestCommonSubsequence(string text1, string text2) {
        int n = text1.length(), m = text2.length();
        vector<vector<int>> dp(n+1, vector<int>(m+1, 0));
        
        // Bottoms Up Approach
        for(int i=n-1; i>=0; i--){
            for(int j=m-1; j>=0; j--){
                if(text1[i] == text2[j]){
                    // If Char at text1[i] & text2[j] are equal
                    // We add 1 to our answer as its incresing
                    dp[i][j] = 1 + dp[i+1][j+1];
                }
                else{
                    // If they arent equal, we sustitue right val or down val of LCS
                    // As this particular combination did not contribue to LCS
                    dp[i][j] = max(dp[i][j+1], dp[i+1][j]);
                }
            }
        }
        return dp[0][0];
    }
};