class Solution {
public:
    int edgeScore(vector<int>& edges) {
        unordered_map<long long , long long> mpp;
        for(long long i=0; i<edges.size(); i++){
            mpp[edges[i]] += i;
        }
        long long maxi = INT_MIN, ans = -1;
        for(auto it : mpp){
            if(it.second >= maxi){
                if(maxi == it.second) ans = min(ans, it.first);
                else ans = it.first;
                maxi = it.second;
            }
        }
        return ans;
    }
};