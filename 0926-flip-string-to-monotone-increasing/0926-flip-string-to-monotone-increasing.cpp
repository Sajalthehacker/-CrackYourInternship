class Solution {
public:
    int minFlipsMonoIncr(string s) {
        int n = s.size();
        int suff[n];
        
        for(int i=n-1; i>=0; i--){
            if(i == n-1){
                if(s[i] == '0') suff[i] = 1;
                else suff[i] = 0;
            }
            else {
                if(s[i] == '0') suff[i] = suff[i+1] + 1;
                else suff[i] = suff[i+1];
            }
        }
        
        int ans = INT_MAX, pref = 0;

        for(int i=0; i<n; i++){
            if(i == n-1) ans = min(ans, pref);
            else {
                if(i == 0) ans = min(ans, suff[i]);
                ans = min(ans , pref + suff[i+1]);
            }
            if(s[i] == '1') pref++;
        }
        return ans;
        
    }
};