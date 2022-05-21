class Solution {
public:
    int maxArea(vector<int>& nums) {
        int l=0, r=nums.size()-1;
        int vol = 0;
        
        while(l<r){
            vol = max(vol, (r-l)*min(nums[l], nums[r]));
            if(nums[l]<nums[r]) l++;
            else r--;
        }
        return vol;
    }
};