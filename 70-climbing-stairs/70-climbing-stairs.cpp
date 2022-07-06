class Solution {
public:
    int climbStairs(int n) {
        // Tabulation
        if(n <= 2) return n;
        
        int b = 1, a = 1, res;
        for(int i=n-2; i>=0; i--){
            res = b + a;
            a = b;
            b = res;
        }
        return res;
    }
};