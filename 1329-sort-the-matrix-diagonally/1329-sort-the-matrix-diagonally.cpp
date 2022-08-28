class Solution {
public:
    vector<vector<int>> diagonalSort(vector<vector<int>>& mat) {
        int n = mat.size(), m = mat[0].size();
        
        unordered_map<int, priority_queue<int, vector<int>, greater<int>>> mpp;
        
        
        for(int i=0; i<n; i++){
           for(int j=0; j<m; j++){
               mpp[i-j].push(mat[i][j]);
           }
        }
        for(int i=0; i<n; i++){
           for(int j=0; j<m; j++){
               mat[i][j] = mpp[i-j].top();
               mpp[i-j].pop();
           }
        }
        
        return mat;
    }
};