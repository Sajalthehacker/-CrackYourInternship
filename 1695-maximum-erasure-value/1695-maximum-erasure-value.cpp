class Solution {
public:
    int maximumUniqueSubarray(vector<int>& nums) {
        int sum = 0, maxi = 0;
        int n = nums.size();
        
        vector<int> pre(n+1, 0);
        
        unordered_map<int, int> mpp;
        
        for(int j=0, i=0; j<n; j++){
            pre[j+1] = pre[j] + nums[j];
            if(mpp.find(nums[j]) != mpp.end())
                i = max(i, mpp[nums[j]] + 1);
            
            maxi = max(maxi, pre[j+1] - pre[i]);
            mpp[nums[j]] = j;
        }
        return maxi;
        
    }
};