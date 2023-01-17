class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        // hash prev sub array sums
        unordered_map<int, int> mpp;
        int pref = 0, ans = 0;
        mpp[0]++;
        for(int it : nums){
            pref += it;
            if(mpp.find(pref - k) != mpp.end()) 
                ans += mpp[pref - k];
            mpp[pref] ++;
        }
        return ans;
    }
};