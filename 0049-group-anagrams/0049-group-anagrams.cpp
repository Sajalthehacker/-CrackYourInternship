class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        int n = strs.size();
        vector<vector<string>> ans;
        map<string, vector<string>> arr;
        for(auto it : strs) {
            string curr = it;
            sort(it.begin(), it.end());
            arr[it].push_back(curr);
        }
        for(auto it : arr) ans.push_back(it.second);
        
        return ans;
    }
};