class Solution {
public:
    int longestPalindrome(string s) {
        map<char, int> mpp;
        int odd = 0, ans = 0;
        for(char it : s) mpp[it]++;
        for(auto it : mpp){
            if(it.second % 2 == 0) ans += it.second;
            else {
                ans += it.second-1;
                odd = 1;
            }
        }
        return ans+odd;
    }
};