class Solution {
public:
    int dir[4][2] = {{1, 0}, {-1, 0}, {0, -1}, {0, 1}};
    void dfs(int i, int j, vector<vector<bool>> &vis, vector<vector<char>>& board){
        int n = board.size(), m = board[0].size();
        if(i<0 || i>=n || j<0 || j>=m || vis[i][j] || board[i][j] != 'O') return;
        vis[i][j] = true;
        board[i][j] = 'T';
        for(auto it : dir){
            dfs(i+it[0], j+it[1], vis, board);
        }
    }
    
    void solve(vector<vector<char>>& board) {
        int n = board.size(), m = board[0].size();
        vector<vector<bool>> vis(n, vector<bool>(m, false));
        for(int i=0; i<n; i++){
            if(board[i][0] == 'O') dfs(i, 0, vis, board);
            if(board[i][m-1] == 'O') dfs(i, m-1, vis, board);
        }
        for(int i=0; i<m; i++){
            if(board[0][i] == 'O') dfs(0, i, vis, board);
            if(board[n-1][i] == 'O') dfs(n-1, i, vis, board);
        }
        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                if(board[i][j] == 'O') board[i][j] = 'X';
                else if(board[i][j] == 'T') board[i][j] = 'O';
            }
        }
    }
};