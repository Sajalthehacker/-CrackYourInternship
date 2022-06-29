class Solution {
private:
    static bool comp(vector<int>&a, vector<int>&b){
        if(a[0] == b[0]) return a[1] < b[1];
        return a[0] > b[0];
    }
public:
    vector<vector<int>> reconstructQueue(vector<vector<int>>& people) {
        sort(people.begin(), people.end(), comp);
        vector<vector<int>> que;
        
        for(auto it : people){
            que.insert(que.begin() + it[1], it);
        }
        return que;
    }
};