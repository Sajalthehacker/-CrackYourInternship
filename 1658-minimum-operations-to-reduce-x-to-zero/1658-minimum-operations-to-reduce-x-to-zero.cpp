class Solution {
public:
    int minOperations(vector<int>& nums, int x) {
        // Find the needed subarray sum, which will be deleted from array
        int sum = 0;
        for(auto it : nums) sum += it;
        sum -= x;
        
        // Find the largest subarray with (sum-x) sum
        int i=0, j=0, currSum=0, maxL = -1;
        while(i<=j && j<nums.size()){
            currSum += nums[j];
            
            while(i<=j && currSum > sum) currSum -= nums[i++];
            if(currSum == sum) maxL = max(maxL, j-i+1);
            
            j++;
        }
        if(maxL == -1) return -1;
        return nums.size() - maxL;
        
    }
};