class Solution {
public:
    int carFleet(int target, vector<int>& position, vector<int>& speed) {
        vector<pair<int, int>> cars;
        for(int i=0; i<speed.size(); i++){
            cars.push_back({position[i], speed[i]});
        }
        sort(cars.begin(), cars.end());
        vector<double> times;
        for(auto it : cars){
            times.push_back((target - it.first) * (1.0) / it.second);
        }
        int n = speed.size();
        int ans = n;
        for(int i=n-2; i>=0; i--){
            if(times[i+1] >= times[i]){
                ans--;
                times[i] = times[i+1];
            }
        }
        return ans;
    }
};