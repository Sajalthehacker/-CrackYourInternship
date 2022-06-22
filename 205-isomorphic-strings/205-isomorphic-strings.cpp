class Solution {
public:
    bool isIsomorphic(string s, string t) {
        if(s.length() != t.length()) return false;
        // Hashing Implementation
        int sInd[129] = {0}, tInd[129] = {0};
        for(int i=0; i<s.length(); i++){
            if(sInd[s[i]] != tInd[t[i]]) return false; // Values aren't same
            
            sInd[s[i]] = tInd[t[i]] = i+1;
        }
        return true;
    }
};