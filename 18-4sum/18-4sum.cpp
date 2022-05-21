class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        vector<vector<int>> quads;
        int n = nums.size();

        sort(nums.begin(), nums.end());
        
        for(int i=0; i<n; i++){
            // if(i>0 && i<n-3 && nums[i]==nums[i-1]) continue;
            for(int j=i+1; j<n; j++){
                // if(j>0 && j<n-2 && nums[j]==nums[j-1]) continue;
                int l=j+1, r=n-1;
                int rem = target - nums[i] - nums[j];
                while(l<r){
                    int sum = nums[l]+nums[r];
                    if(sum == rem){
                        quads.push_back(vector<int>{nums[i], nums[j], nums[l], nums[r]});
                        while(l<r && nums[l]==nums[l+1]) l++;
                        while(r>l && nums[r]==nums[r-1]) r--;
                        l++;
                        r--;
                    }
                    else if(sum > rem) r--;
                    else l++;
                }
                while(j+1<n && nums[j+1] == nums[j]) j++;
            }
            while(i+1<n && nums[i+1] == nums[i]) i++;
        }
        return quads;
    }
};