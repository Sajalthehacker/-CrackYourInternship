class Solution {
public:
    int numTrees(int n) {
        int numTrees[n+1];
        numTrees[0] = numTrees[1] = 1;
        
        for(int i=2; i<=n; i++){
            numTrees[i] = 0;
            for(int j=0; j<i; j++){
                numTrees[i] += numTrees[j] * numTrees[i-j-1];
            }
        }
        return numTrees[n];
    }
};