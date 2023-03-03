class Solution {
public:
    int strStr(string haystack, string needle) {
        // Brute
        int n = haystack.size(), m = needle.size();

        for(int i=0; i<n; i++)
            if(haystack[i] == needle[0] && haystack.substr(i, m) == needle) return i;
        
        return -1;
        
        
    }
};