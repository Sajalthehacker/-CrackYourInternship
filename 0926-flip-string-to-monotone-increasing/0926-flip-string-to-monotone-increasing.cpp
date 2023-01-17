class Solution {
public:
    int minFlipsMonoIncr(string s) {
        int n = s.size();
        int pref[n], suff[n];
        for(int i=0; i<n; i++){
            if(i == 0){
                if(s[i] == '1') pref[i] = 1;
                else pref[i] = 0;
            }
            else{
                if(s[i] == '1') pref[i] = pref[i-1] + 1;
                else pref[i] = pref[i-1];
            }
        }
        
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
        
        int ans = INT_MAX;
        // for(int it : pref) cout << it << " ";
        // cout << endl;
        // for(int it : suff) cout << it << " ";

        for(int i=0; i<n; i++){
            if(i == n-1) ans = min(ans, pref[i]);
            else {
                if(i == 0) ans = min(ans, suff[i]);
                ans = min(ans , pref[i] + suff[i+1]);
            }
        }
        return ans;
        
    }
};