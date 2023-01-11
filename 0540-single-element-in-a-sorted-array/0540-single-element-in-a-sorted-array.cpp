class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) {
        if(nums.size() == 1) return nums[0];
        
        int low = 0, high = nums.size() - 1, mid;
        
        while(low < high){
            mid = low + (high - low) / 2;
            // number ^ 1 flips the last bit,
            // if num is odd it becomes odd - 1
            // if num is even it becomes even + 1 
            
            // If this isnt undersytandable , refer previous submissions
            if(nums[mid] == nums[mid^1]){  
                low = mid + 1;
            }
            else high = mid;
        }
        return nums[low];
        
    }
};