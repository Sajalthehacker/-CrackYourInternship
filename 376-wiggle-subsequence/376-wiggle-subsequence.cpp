class Solution {
public:
    int wiggleMaxLength(vector<int>& nums) {
        if(nums.size() == 1) return 1;
        
        int currDiff , prevDiff = nums[1] - nums[0];
        int lws = 0;
        
        if(prevDiff != 0) lws = 2;
        else lws = 1;
        
        for(int i=2; i<nums.size(); i++){
            currDiff = nums[i] - nums[i-1];
            if((prevDiff <=0 && currDiff>0) ||(prevDiff>=0 && currDiff<0 )){
                lws++;
                prevDiff = currDiff;
            }
        }
        return lws;
    }
};