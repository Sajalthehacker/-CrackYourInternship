class Solution {
public:
    int rob(vector<int>& nums) {
        // this sub is memory optimised visit prev sub if confused
        int n = nums.size();
        if(n == 1) return nums[0];
        
        int prev1 = nums[0], prev2 = 0, ans;
        
        for(int i=1; i<n; i++){
            int take = nums[i];
            if(i > 1) take += prev2;
            
            int not_take = prev1;
            
            ans = max(take, not_take);
            
            prev2 = prev1;
            prev1 = ans;
        }
        return ans;
    }
};