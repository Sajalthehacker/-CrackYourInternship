class Solution {
public:
    void fn(int ind, vector<int> &curr, vector<int> &nums, set<vector<int>> &stt){
        if(ind == nums.size()){
            if(curr.size() >= 2) stt.insert(curr); 
            return;
        }
        if(curr.size() >= 2) 
            stt.insert(curr);
        
        if(curr.empty() || curr.back() <= nums[ind]){
            curr.push_back(nums[ind]);
            fn(ind+1, curr, nums, stt);
            curr.pop_back();
        }
        fn(ind+1, curr, nums, stt);
    }
    
    vector<vector<int>> findSubsequences(vector<int>& nums) {
        set<vector<int>> stt;
        vector<vector<int>> ans;
        vector<int> curr;
        fn(0, curr, nums, stt);
        for(auto it : stt){
            ans.push_back(it);
        }
        return ans;
    }
};