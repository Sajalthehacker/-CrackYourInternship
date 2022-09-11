class Solution {
private:
    bool check(int time, int m, int k, vector<int> &bloomDay){
        int boquetCnt = 0, t=0;
        for(int it : bloomDay){
            if(it <= time){
                t++;
                if(t == k){
                    boquetCnt++;
                    t = 0;
                }
            }
            else{
                    t = 0;
            }
        }
        return boquetCnt >= m;
    }
public:
    int minDays(vector<int>& bloomDay, int m, int k) {
        // MnFn : F F F F F T T T T T -> finding first true
        int start = 0, end = INT_MAX, mid;
        
        while(end - start > 1){
            mid = start + (end - start) / 2;
            if(check(mid, m, k, bloomDay)){
                end = mid;
            }
            else start = mid + 1;
        }
        if(check(start, m, k, bloomDay)) return start;
        else if(check(end, m, k, bloomDay)) return end;
        else return -1;
    }
};