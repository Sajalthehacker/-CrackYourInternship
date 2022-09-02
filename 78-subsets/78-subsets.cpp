class Solution {
private:
    void subsetSum(int ind, vector<int>& nums, vector<int>& ds, vector<vector<int>>& ans){
        if(ind==nums.size()){
            ans.push_back(ds);
            return;
        }
        ds.push_back(nums[ind]);
        subsetSum(ind+1, nums, ds, ans);
        ds.pop_back();
        subsetSum(ind+1, nums, ds, ans);
    }
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        vector<int> ds;
        vector<vector<int>> ans;
        subsetSum(0, nums, ds, ans);
        return ans;
    }
};