class Solution {
private:
    int n;
    void recurPermute(int ind, vector<int>& nums, vector<vector<int>> &ans){
        if(ind == n){
            ans.push_back(nums);
            return;
        }
        
        for(int i=ind; i<n; i++){
            swap(nums[ind], nums[i]);
            recurPermute(ind+1, nums, ans);
            swap(nums[ind], nums[i]);
        }
    }
public:
    vector<vector<int>> permute(vector<int>& nums) {
        n = nums.size();
        vector<vector<int>> ans;
        recurPermute(0, nums, ans);
        return ans;
    }
};