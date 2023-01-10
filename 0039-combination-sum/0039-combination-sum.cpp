class Solution {
private:
    void fn(int ind, int t, vector<int> &sub, vector<int>& cand, vector<vector<int>> &ans){
        if(ind == cand.size()){
            if(t == 0) ans.push_back(sub);
            return;
        }
        if(t - cand[ind] >= 0){    
            sub.push_back(cand[ind]);
            fn(ind, t - cand[ind], sub, cand, ans);
            sub.pop_back();
        }
    
        fn(ind+1, t, sub, cand, ans);
    }
public:
    vector<vector<int>> combinationSum(vector<int>& cand, int t) {
        vector<vector<int>> ans;
        vector<int> sub;
        fn(0, t, sub, cand, ans);
        return ans;
    }
};