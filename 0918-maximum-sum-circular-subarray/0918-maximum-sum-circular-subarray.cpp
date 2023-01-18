class Solution {
public:
    int maxSubarraySumCircular(vector<int>& nums) {
        //case 1 : mid of array
        int currMini = 0, currMax = 0, maxi = INT_MIN, mini = INT_MAX, totalSum = 0;
        for(int it : nums){
            currMax = max(currMax + it, it);
            maxi = max(maxi, currMax); // gets the max sub array sum
            
            currMini = min(currMini + it, it);
            mini = min(mini, currMini);
            
            totalSum += it;
        }
        
        if(maxi < 0) return maxi;
        else return max(maxi, totalSum - mini);
    }
};