class Solution {
    static bool comp(vector<int>& a, vector<int>& b){
        return a[1]>=b[1];
    }
public:
    int maximumUnits(vector<vector<int>>& boxTypes, int t) {
        sort(boxTypes.begin(), boxTypes.end(), comp);
        int units = 0;
        
        for(auto it : boxTypes){
            if(it[0] < t){
                t -= it[0];
                units += it[0]*it[1];
            }
            else{
                units += t*it[1];
                break;
            }
        }
        return units;
    }
};