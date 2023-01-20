class Solution {
public:
    void fn(int ind, vector<int> &curr, vector<int> &nums, set<vector<int>> &stt){
        if(ind == nums.size()){
            if(curr.size() >=2){
                for(int i=1; i<curr.size(); i++)
                    if(curr[i] < curr[i-1]) return;
                stt.insert(curr); 
            }
            return;
        }
        else if(curr.size() >= 2) {
            bool flag = true;
            for(int i=1; i<curr.size(); i++){
                if(curr[i] < curr[i-1]) {
                    flag = false;
                    break;
                }
            }
            if(flag) stt.insert(curr);
        }
        
        curr.push_back(nums[ind]);
        fn(ind+1, curr, nums, stt);
        curr.pop_back();
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