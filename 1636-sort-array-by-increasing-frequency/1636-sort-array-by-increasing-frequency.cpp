class Solution {
public:
    static bool compp(pair<int, int> &p1, pair<int, int> &p2){
        if(p1.first == p2.first) return p1.second > p2.second;
        return p1.first < p2.first;
    }
    vector<int> frequencySort(vector<int>& nums) {
        unordered_map<int, int> mpp;
        for(int it : nums) mpp[it]++;
        vector<pair<int, int>> temp;
        for(auto it : mpp) temp.push_back({it.second, it.first});
        sort(temp.begin(), temp.end(), compp);
        nums.clear();
        for(auto it : temp){
            for(int i=0; i<it.first; i++) nums.push_back(it.second);
        }
        return nums;
    }
};