class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        string ans = "";
        
        sort(strs.begin(), strs.end());
        string s1 = strs[0];
        string s2 = strs[strs.size()-1];
        
        for(int i=0; i<s1.length(); i++){
            if(s1[i]==s2[i]){
                ans += s1[i]; 
            }
            else return ans;
        }

        return ans;
    }
};