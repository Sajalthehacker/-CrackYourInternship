class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int currSum = 0, maxSum = INT_MIN;
        for(int it : nums){
            currSum += it;
            maxSum = max(maxSum, currSum);
            if(currSum < 0) currSum = 0;
        }
        return maxSum;
    }
};