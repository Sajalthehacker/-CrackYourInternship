class Solution {
public:
    bool isSubsequence(string s, string t) {
        int i = 0, n = s.length(), j = 0, m = t.length();
        // Two pointers
        while(i<n && j<m){
            if(s[i] == t[j]) i++;
            j++;
        }
        return i==n;
    }
};