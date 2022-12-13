class Solution {
public:
    int minimumDeletions(string s) {
        int n = s.size();
        int preB[n];
        int suffA[n];
        
        if(s[0] == 'b') preB[0] = 1;
        else preB[0] = 0;
        if(s[n-1] == 'a') suffA[n-1] = 1;
        else suffA[n-1] = 0;

        for(int i=1; i<n; i++){
            if(s[i] == 'b') preB[i] = preB[i-1] + 1;
            else preB[i] = preB[i-1];
            
            if(s[n-i-1] == 'a') suffA[n-i-1] = suffA[n-i] + 1;
            else suffA[n-i-1] = suffA[n-i];
        }
        int ans = INT_MAX;
        for(int i=0; i<n; i++){
            if((preB[i] == 1 && suffA[i] == 0) || (preB[i] == 0 && suffA[i] == 1)) return 0;
            ans = min(ans, preB[i] + suffA[i] - 1);
        }
        return ans;
    }
};