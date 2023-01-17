class Solution {
public:
    int minFlipsMonoIncr(string s) {
        int n = s.size();
        
        // Can be done using pref, suff
        // on every pointer, left of ptr should be zeros , right of them should be 1's
        
        int ans = 0, pref = 0;

        for(char it : s){
            if(it == '1') pref++;
            else{
                ans = min(ans+1, pref);
            }
        }
        return ans;
    }
};