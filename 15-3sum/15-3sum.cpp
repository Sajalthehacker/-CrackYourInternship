class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> triplets;
        sort(nums.begin(), nums.end());
        
        int n = nums.size();
        for(int i=0; i<n-2; i++){
            if(i>0 && nums[i]==nums[i-1]) continue;
            int rem = 0 - nums[i];
            
            int l=i+1, r=n-1;
            while(l<r){
                if(nums[l]+nums[r] == rem){
                    triplets.push_back(vector<int> {nums[i], nums[l], nums[r]});
                    while(l<r && nums[l]==nums[l+1]) l++;
                    while(r>l && nums[r]==nums[r-1]) r--;
                    l++;
                    r--;
                }
                else if(nums[l]+nums[r] < rem) l++;
                else r--;
            }
            
        }
        return triplets;
    }
};