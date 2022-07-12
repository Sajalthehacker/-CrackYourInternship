class Solution {
public:
    int uniquePaths(int m, int n) {
        int total = m + n - 2;
        int r = min(n, m) - 1;
        double res = 1;
        
        for(int i=1; i<=r; i++, total--){
            res = res * total / i;
        }
        
        return (int)res;
    }
};