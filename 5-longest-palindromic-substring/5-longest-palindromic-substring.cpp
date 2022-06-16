class Solution {
private:
    void checkPalindromes(int l, int r, int n, int &maxL, int &ind1, int &ind2, string s){
        while(l>=0 && r<n && s[l]==s[r]){
            if(r-l+1 > maxL){
                maxL = r-l+1;
                ind1 = l;
                ind2 = r;
            }
            r++; l--;
        }
    }
public:
    string longestPalindrome(string s) {
        int n = s.length();
        int ind1 = -1, ind2 = -1, maxL = 0;
        for(int i=0; i<n; i++){
            // Check for Odd Length Palindrome
            checkPalindromes(i, i, n, maxL, ind1, ind2, s);
            
            // Check for Even Length Palindrome
            checkPalindromes(i, i+1, n, maxL, ind1, ind2, s);
        }
        string ans = s.substr(ind1, ind2-ind1+1);
        return ans;
    }
};