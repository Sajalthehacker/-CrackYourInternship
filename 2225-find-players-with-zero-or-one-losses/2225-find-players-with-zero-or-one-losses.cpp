class Solution {
public:
    vector<vector<int>> findWinners(vector<vector<int>>& matches) {
        unordered_map<int, int> mpp;
        unordered_set<int> stt;
        vector<vector<int>> ans(2);
        
        for(auto it : matches){
            mpp[it[1]]++;
            stt.insert(it[0]);
            if(stt.find(it[1]) != stt.end()) stt.erase(it[1]);
        }
        for(auto it : mpp){
            if(it.second == 1) ans[1].push_back(it.first);
            
            if(stt.find(it.first) != stt.end()) stt.erase(it.first);

        }
        for(auto it : stt){
            ans[0].push_back(it);
        }
        sort(ans[0].begin(), ans[0].end());        
        sort(ans[1].begin(), ans[1].end());
        
        return ans;
    }
};