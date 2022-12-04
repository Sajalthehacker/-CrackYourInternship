class Solution {
public:
    int minimumAverageDifference(vector<int>& nums) {
        int n = nums.size();
        long long rSum = 0, lSum = 0;
        for(int it : nums) rSum += it;
        
        int ind = 0, mini = INT_MAX;
        for(int i=0; i<n; i++){
            lSum += nums[i];
            rSum -= nums[i];
            
            int left = lSum / (i+1);
            int right;
            if(i == n-1) right = 0;
            else right = rSum / (n - i - 1);
            
            if(abs(left - right) < mini){
                mini = abs(left - right);
                ind = i;
            }
        }
        return ind;
    }
};