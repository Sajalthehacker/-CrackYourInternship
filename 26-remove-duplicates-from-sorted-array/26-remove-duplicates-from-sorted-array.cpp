class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int k = 1;
        int i=1, j=1;
        
        while(j<nums.size()){
            if(nums[j] != nums[j-1]){
                nums[i++] = nums[j];
                k++;
            }
            j++;
        }
        return k;
    }
};