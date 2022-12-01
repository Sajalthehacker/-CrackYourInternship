class Solution {
private:
    static bool comp(vector<int> &a, vector<int> &b){
        if(a[0] == b[0]) return a[1] < b[1];
        return a[0] < b[0];
    }
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        sort(intervals.begin(), intervals.end(), comp);
        vector<vector<int>> ans;
        int n = intervals.size();
        vector<int> prev = intervals[0];
        
        for(int i=1; i<n; i++){
            if(prev[1] >= intervals[i][0]){
                prev = {min(prev[0], intervals[i][0]), max(prev[1], intervals[i][1])};
            }
            else{
                ans.push_back(prev);
                prev = intervals[i];
            }
        }
        ans.push_back(prev); // last interval
        return ans;
    }
};