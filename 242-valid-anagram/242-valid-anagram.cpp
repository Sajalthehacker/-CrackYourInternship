class Solution {
public:
    bool isAnagram(string s, string t) {
        
        if(s.length() != t.length()) return false;
        
        int s_arr[26] = {0};
        int t_arr[26] = {0};

        for(char it : s) s_arr[it - 'a']++;
        for(char it : t) t_arr[it - 'a']++;
        
        for(int i=0; i<26; i++) 
            if(s_arr[i] != t_arr[i]) 
                return false;
        
        return true;


    }
};