class Solution {
private:
    bool check(int speed, int h, vector<int>& piles){
        int time = 0;
        for(int it : piles){
            time += ceil(it*(1.0)/speed);
        }
        return time <= h;
    }
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        // Here if speed of eating results in monotonic fn : F F F F T T T T  T
        // Need to find the first t in the MnFn
        int start = 1, end = INT_MAX, mid;
        
        while(end - start > 1){
            mid = start + (end - start) / 2;
            if(check(mid, h, piles)){
                // can be ans, but have to check for less speed
                end = mid;
            }
            else start = mid + 1;
        }
        
        if(check(start, h, piles)) return start;
        else return end;
    }
};