class Solution {
public:
    vector<vector<int>> diagonalSort(vector<vector<int>>& mat) {
        int n = mat.size(), m = mat[0].size();
        
        for(int i=0; i<n; i++){
           for(int j=0; j<m; j++){
               int r = i, c = j;
               while(r<n && c<m){
                   if(mat[i][j] > mat[r][c])
                       swap(mat[i][j], mat[r][c]);
                   r++;
                   c++;
               }
           }
        }
        
        return mat;
    }
};