class Solution {
public:
    vector<vector<int>> generate(int n) {
        vector<vector<int>> tri(n);
        tri[0].push_back(1);
        for(int i=1; i<n; i++){
            for(int j=0; j<i+1; j++){
                if(j == 0 || j == i) tri[i].push_back(1);
                else{
                    tri[i].push_back(tri[i-1][j-1] + tri[i-1][j]);
                }
            }
        }
        return tri;
    }
};