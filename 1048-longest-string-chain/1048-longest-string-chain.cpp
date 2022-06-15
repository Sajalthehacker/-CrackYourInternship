class Solution {
private:
    bool static comp(string &s1, string &s2){
        return s1.size() > s2.size();
    }
public:
    int longestStrChain(vector<string>& words) {
        int n = words.size();
        sort(words.begin(), words.end(), comp);
        
        unordered_map<string, int> mpp;
        for(int i=0; i<n; i++){
            mpp[words[i]] = i;
        }
        
        // dp Starts from here
        vector<int> dp(n+1, 1);
        int ans = 1;
        
        for(int i=0; i<n; i++){
            for(int j=0; j<words[i].size(); j++){
                string pred = words[i].substr(0, j) + words[i].substr(j+1);
                if(mpp.find(pred) != mpp.end()){
                    dp[mpp[pred]] = max(dp[mpp[pred]], 1 + dp[i]);
                    ans = max(ans, dp[mpp[pred]]);
                }
            }
        }
        return ans;
    }
};