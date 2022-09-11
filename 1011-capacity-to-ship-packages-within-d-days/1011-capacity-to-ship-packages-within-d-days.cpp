class Solution {
private:
    bool check(int maxCap, int days, vector<int> weights){
        int dayCnt = 1, currWt = 0;
        for(int it : weights){
            if(it > maxCap) return false;
            
            if(currWt + it > maxCap){
                dayCnt++;
                currWt = it;
            }
            else currWt += it;
        }
        
        return dayCnt <= days;
    }
public:
    int shipWithinDays(vector<int>& weights, int days) {
        // MnFn : F F F F T T T T T
        int start = 1, end = INT_MAX, mid;
        while(end - start > 1){
            mid = start + (end - start) / 2;
            
            if(check(mid, days, weights)){
                end = mid;
            }
            else start = mid + 1;
        }
        
        if(check(start, days, weights)) return start;
        else return end;
    }
};