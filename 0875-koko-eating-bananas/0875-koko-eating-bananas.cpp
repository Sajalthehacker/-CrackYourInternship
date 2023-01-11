class Solution {

public:
    bool check(int m, vector<int>&piles, int h){
        int cnt = 0;
        for(int it : piles){
            cnt += (it/m);
            if(it%m) cnt++;
        }
        
        return cnt <= h;
    }
    
    
    int minEatingSpeed(vector<int>& piles, int h) {
        int n = piles.size();
        int l = 1, r = 1000000000, m;
        
        while(r - l >= 1){
            m = l + (r - l) / 2;
            if(check(m, piles, h)){
                r = m;
            }
            else l = m+1;
        }
        if(check(l, piles, h)) return l;
        else return r;
        
    }
};