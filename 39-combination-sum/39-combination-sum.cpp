class Solution {
private:
    vector<int> ds;
    vector<vector<int>> ans;
    int n;
    
    void cSum(int ind, int target, vector<int>& candidates){
        if(ind == n){
            if(target==0){
                ans.push_back(ds);
            }
            return;
        }
        
        if(candidates[ind] <= target){
            ds.push_back(candidates[ind]);
            cSum(ind, target-candidates[ind], candidates);
            ds.pop_back();
        }
        cSum(ind+1, target, candidates);
        
    }
    
    
    
public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        n = candidates.size();
        int ind = 0;
        cSum(ind, target, candidates);
        return ans;
    }
};