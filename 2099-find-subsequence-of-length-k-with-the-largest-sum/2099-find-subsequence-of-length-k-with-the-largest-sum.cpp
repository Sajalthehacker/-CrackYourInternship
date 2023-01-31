class Solution {
public:
    static bool comp(pair<int, int> &p1, pair<int, int> &p2){
        return p1.second < p2.second;
    }
    vector<int> maxSubsequence(vector<int>& nums, int k) {
        vector<pair<int, int>> arr;
        vector<int> ans;
        for(int i=0; i<nums.size(); i++) arr.push_back({nums[i], i});
        sort(arr.begin(), arr.end(), greater<pair<int, int>>());
        sort(arr.begin(), arr.begin()+k, comp);
        for(int i=0; i<k; i++) ans.push_back(arr[i].first);
        return ans;
    }
};