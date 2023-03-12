class Solution {
public:
    bool fn(int n, int m, string &s, string &p, vector<vector<int>> &dp){
        // Base Case
        if(n < 0 && m < 0) return true;
        if(m < 0 ) return false;
        if(n < 0) {
            for(int i =0; i<=m; i++) 
                if(p[i] != '*') return false;
            return true;
        }
        
        if(dp[n][m] != -1) return dp[n][m];
        
        bool f1, f2, f3;
        f1 = f2 = f3 = false;
        if(p[m] == '?' || s[n] == p[m]){
            // match it and move forward
            f1 = fn(n-1, m-1, s, p, dp);
        }
        else{
            if(p[m] == '*'){
                f3 = fn(n-1, m, s, p, dp);
                f2 = fn(n, m-1, s, p, dp);
            }
            else return false;
        }
        return dp[n][m] = (f1 || f2 || f3);
        
    }
    
    bool isMatch(string s, string p) {
        int n = s.size(), m = p.size();
        vector<vector<int>> dp(n, vector<int>(m, -1));
        return fn(n-1, m-1, s, p, dp);
    }
};