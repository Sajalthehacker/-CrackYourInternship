class Solution {
public:
    int findTheCity(int n, vector<vector<int>>& edges, int distanceThreshold) {
        vector<vector<int>> mat(n, vector<int>(n, 1e9));
        for(auto edge : edges){
            mat[edge[0]][edge[1]] = edge[2];
            mat[edge[1]][edge[0]] = edge[2];
        }
        for(int i=0; i<n; i++) mat[i][i] = 0;
        
        for(int k=0; k<n; k++){
            for(int i=0; i<n; i++){
                for(int j=0; j<n; j++){
                    if(mat[i][k] == 1e9 || mat[k][j] == 1e9) continue;
                    mat[i][j] = min(mat[i][j], mat[i][k] + mat[k][j]);
                }
            }
        }
        int city = -1, cityCnt = n;
        for(int i=0; i<n; i++){
            int cnt = 0;
            for(int j=0; j<n; j++){
                if(mat[i][j] <= distanceThreshold) cnt++;    
            }
            if(cnt <= cityCnt){
                cityCnt = cnt;
                city = i;
            }
        }
        return city;
        
    }
};