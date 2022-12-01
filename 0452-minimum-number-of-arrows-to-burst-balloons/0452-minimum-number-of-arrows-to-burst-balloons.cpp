class Solution {
private:
    static bool comp(vector<int> &a, vector<int> &b){
        if(a[1] == b[1]) return a[0] < b[0];
        return a[1] < b[1];
    }
public:
    int findMinArrowShots(vector<vector<int>>& points) {
        int n = points.size();
        sort(points.begin(), points.end(), comp);
        
        int prev = points[0][1];
        int ans = 1;
        for(int i=1; i<n; i++){
            if(prev < points[i][0]){
                prev = points[i][1];
                ans++;
            }
            // else prev = points[i][1];
        }
       return ans;
    }
};
