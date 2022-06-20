class Solution {
private:
    int n, m;
    int directions[4][2] = {{1, 0}, {0 , 1}, {-1, 0}, {0, -1}};
    
    void dfs(int i, int j, vector<vector<char>>& board){
        if(i<0 || j<0 || i>=n || j>=m || board[i][j] != 'O')
            return;

        board[i][j] = '#'; // Denotes we cant capture this part
        for(auto it : directions){
            dfs(i+it[0], j+it[1], board);
        }
    }
public:
    void solve(vector<vector<char>>& board) {
        n = board.size();
        m = board[0].size();
        
        // Travel Left Boundary
        for(int i=0; i<n; i++) if(board[i][0] == 'O') dfs(i, 0, board);
        for(int i=0; i<n; i++) if(board[i][m-1] == 'O') dfs(i, m-1, board);
        for(int i=0; i<m; i++) if(board[0][i] == 'O') dfs(0, i, board);
        for(int i=0; i<m; i++) if(board[n-1][i] == 'O') dfs(n-1, i, board);
        
        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                if(board[i][j] == '#') board[i][j] = 'O';
                else if(board[i][j] == 'O')  board[i][j] = 'X';
            }
        }
    }
};