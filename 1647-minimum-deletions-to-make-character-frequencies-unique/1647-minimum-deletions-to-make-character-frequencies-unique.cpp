class Solution {
public:
    int minDeletions(string s) {
        
        vector<int> freq(26, 0);
        for(int i=0; i<s.size(); i++){
            freq[s[i]-'a']++;
        }
        sort(freq.begin(), freq.end(), greater<int>());
        
        int ans = 0, prev = freq[0];
        
        for(int i=0; i<26; i++){
            if(freq[i] > prev){
                if(prev > 0)
                    ans += freq[i] - prev;
                else ans += freq[i];
            }
            prev = min ( freq[i]-1, prev-1);
        }

       
        return ans;
    }
};