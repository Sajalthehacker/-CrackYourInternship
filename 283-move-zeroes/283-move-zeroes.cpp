class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int i=0, j=0, cnt = 0;
        int n = nums.size();
        
        // Application of QuickSelect Algorithm        
        while(j<n){
            if(nums[j] != 0){
                swap(nums[i++] , nums[j]);
            }
            else cnt++;
            j++;
        }
    }
};