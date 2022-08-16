class Solution {
public:
    int firstUniqChar(string s) {
        vector<int> freq(256, 0);
        for(char it : s){
            freq[it]++;
        }
        
        for(int i=0; i<s.length(); i++){
            if(freq[s[i]] == 1){
                return i;
            }
        }
        return -1;
    }
};