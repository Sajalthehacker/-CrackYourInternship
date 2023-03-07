class Solution {
public:
    bool check(long long minTime, vector<int> &time, int totalTrips){
        long long poss = 0;
        for(int it : time){
            poss += (minTime / it);
        }
        return poss >= totalTrips;
    }
    
    long long minimumTime(vector<int>& time, int totalTrips) {
        // F F F T T -> first true would be the answer
        long long start = 1, end = 1e14, mid;
        while(end - start > 1){
            mid = start + (end-start)/2;
            if(check(mid, time, totalTrips)){
                end = mid;
            }
            else start = mid + 1;
        }
        if(check(start, time, totalTrips)) return start;
        else return end;
    }
};