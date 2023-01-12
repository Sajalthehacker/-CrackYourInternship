class Solution {
public:
    static bool compp(vector<int> &a1, vector<int> &a2){
        return (1ll*a1[0]*a1[0] + a1[1]*a1[1] < 1ll*a2[0]*a2[0] + a2[1]*a2[1]);
    }
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        if(points.size() == 1) return points;
        vector<vector<int>> ans;
        sort(points.begin(), points.end(), compp);
        for(int i=0; i<k; i++){
            ans.push_back({points[i][0], points[i][1]});
        }
        return ans;
    }
};