class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int i=0, j=0, cnt = 0;
        int n = nums.size();
        
        while(i<n && nums[i] != 0) i++;
        j = i;
        
        while(j<n){
            if(nums[j] != 0){
                nums[i++] = nums[j];
            }
            else cnt++;
            j++;
        }
        for(int k=n-1; k>=n-cnt; k--) nums[k] = 0;
    }
};