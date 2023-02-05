class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int currSum = 0, maxSum = nums[0];
        for(int it : nums){
            currSum += it;
            maxSum = max(maxSum, currSum);
            currSum = max(0, currSum);
        }
        return maxSum;
    }
};