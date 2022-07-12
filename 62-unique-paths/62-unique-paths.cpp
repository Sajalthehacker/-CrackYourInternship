class Solution {
public:
    int uniquePaths(int m, int n) {
        // Can be done by DP also in TC : O(n*m), SC : O(n*m); refer prev subs
        // this is a combinatorics approach in TC : O(min(n, m)), SC : O(1)
        int total = m + n - 2;
        int r = min(n, m) - 1;
        double res = 1;
        
        for(int i=1; i<=r; i++, total--){
            res = res * total / i;
        }
        
        return (int)res;
    }
};