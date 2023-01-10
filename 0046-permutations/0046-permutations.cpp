class Solution {
private:
    void generatePermuts(int ind, vector<int> &nums, vector<vector<int>> &ans){
        if(ind == nums.size()-1){
            ans.push_back(nums);
            return;
        }
        for(int j = ind; j < nums.size(); j++){
            swap(nums[ind], nums[j]);   // Do 
            generatePermuts(ind+1, nums, ans);
            swap(nums[ind], nums[j]);   // Un-Do
        }
    }
public:
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> ans;
        generatePermuts(0, nums, ans);
        return ans;
    }
};