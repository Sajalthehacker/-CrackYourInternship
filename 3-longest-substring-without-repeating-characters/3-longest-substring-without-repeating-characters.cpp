class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        vector<int> mpp(256, -1);
        
        int l=0, r=0, n=s.size();
        int cnt = 0;
        while(r < n){
            if(mpp[s[r]] != -1){
                l = max(l, mpp[s[r]]+1);
            }
            mpp[s[r]] = r;
            cnt = max(cnt, r-l+1);
            r++;
        }
        return cnt;
    }
};