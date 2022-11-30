class Solution {
public:
    bool uniqueOccurrences(vector<int>& arr) {
        unordered_map<int, int> mpp;
        unordered_set<int> stt;
        for(int it : arr) mpp[it]++;
        for(auto it : mpp){
            if(stt.find(it.second) != stt.end()) return false;
            stt.insert(it.second);
        }
        return true;
    }
};