class Solution {
public:
    void fn(int ind,int n,int k,vector<int>&curr,vector<bool>&vis,vector<vector<int>>&ans){
        if(ind == n){
            if(curr.size() == k) ans.push_back(curr);
            return;
        }
        curr.push_back(ind+1);
        fn(ind+1, n, k, curr, vis, ans);
        curr.pop_back();
    
        fn(ind+1, n, k, curr, vis, ans);
        
    }
    
    vector<vector<int>> combine(int n, int k) {
        vector<vector<int>> ans;
        vector<int> curr;
        vector<bool> vis(n+1, false);

        fn(0, n, k, curr, vis, ans);
        return ans;
    }
};