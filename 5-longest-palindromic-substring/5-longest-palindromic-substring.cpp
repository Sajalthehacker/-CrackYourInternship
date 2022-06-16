class Solution {
public:
    string longestPalindrome(string s) {
        int n = s.length();
        int ind1 = -1, ind2 = -1, maxL = 0;
        for(int i=0; i<n; i++){
            // Check for Odd Length Palindrome
            int l=i, r=i;
            while(l>=0 && r<n && s[l]==s[r]){
                if(r-l+1 > maxL){
                    maxL = r-l+1;
                    ind1 = l;
                    ind2 = r;
                }
                r++; l--;
            }
            
            // Check for Even Length Palindrome
            l=i, r=i+1;
            while(l>=0 && r<n && s[l]==s[r]){
                if(r-l+1 > maxL){
                    maxL = r-l+1;
                    ind1 = l;
                    ind2 = r;
                }
                r++; l--;
            }
        }
        string ans = s.substr(ind1, ind2-ind1+1);
        return ans;
    }
};