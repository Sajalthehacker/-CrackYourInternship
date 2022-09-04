class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        vector<int> ans(2, -1);
        int start = 0, end = nums.size() - 1;
        
        while(start <= end){
            int mid = start + (end - start) / 2;
            if(nums[mid] < target) start = mid + 1;
            else if(nums[mid] > target) end = mid - 1;
            else{
                ans[0] = searchOnSides(target, start, mid, true, nums);
                ans[1] = searchOnSides(target, mid, end, false, nums);  
                break;
            }
        }
        return ans;
    }
    
    // Function to search Right / Left Side
    int searchOnSides(int target, int start, int end, bool onLeft, vector<int> &nums){
        int ind = -1;
        while(start <= end){
            int mid = start + (end - start) / 2;
            
            if(nums[mid] < target) start = mid + 1;
            else if(nums[mid] > target) end = mid - 1;
            else{
                ind = mid;
                if(onLeft) end = mid - 1;
                else start = mid + 1;
            }
        }
        return ind;
    }
};