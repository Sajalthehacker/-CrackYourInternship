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
        for(int i=0; i<n; i++){
            int pStart = intervals[i][0], pEnd = intervals[i][1];
            while(i < n && pEnd >= intervals[i][0]){
                pStart = min(pStart, intervals[i][0]);
                pEnd = max(pEnd, intervals[i][1]);
                i++;
            }
            i--;
            ans.push_back({pStart, pEnd});
        }
        return ans;
    }
};