class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        vector<vector<int>> ans;
        priority_queue<pair<int, pair<int, int>>> pque;
        
        for(auto it : points){
            pque.push({it[0]*it[0] + it[1]*it[1] , {it[0], it[1]}});
            if(pque.size() > k) pque.pop();
        }
        while(!pque.empty()){
            ans.push_back({pque.top().second.first, pque.top().second.second});
            pque.pop();
        }
        return ans;
    }
};