class Solution {
private:
    void fn(int i, vector<int> &nums, vector<int> &ds, vector<vector<int>> &powerSet){
        if(i == nums.size()){
            powerSet.push_back(ds);
            return;
        }
        ds.push_back(nums[i]);
        fn(i+1, nums, ds, powerSet);  // Take Condition
        ds.pop_back();
        fn(i+1, nums, ds, powerSet);  // Not-Take Condition
    }
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> powerSet;
        vector<int> ds;
        
        fn(0, nums, ds, powerSet);
        return powerSet;
    }
};