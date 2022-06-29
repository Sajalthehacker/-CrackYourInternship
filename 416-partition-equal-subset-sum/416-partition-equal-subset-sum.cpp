class Solution {
public:
    bool canPartition(vector<int>& nums) {
        int sum = 0;
        for(int it : nums) sum += it;
        
        if(sum % 2) return false; // sum of 2 equal numbers would be even
        
        int target = sum / 2;
        
        unordered_set<int> dp;
        dp.insert(0);
        
        for(int i=0; i<nums.size(); i++){
            unordered_set<int> nextDp;
            for(int it : dp){
                if(it == target || it+nums[i] == target) return true;
                nextDp.insert(it + nums[i]);
                nextDp.insert(it);
            }
            dp = nextDp;
        }
        return false;
    }
};