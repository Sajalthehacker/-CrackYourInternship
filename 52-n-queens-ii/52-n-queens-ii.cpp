class Solution {
private:
    int cnt = 0;
    
    bool isSafe(int row, int col, int n, vector<string> &board){
        //up-left diagnol
        int rt = row, ct = col;
        while(rt>=0 && ct>=0){
            if(board[rt][ct] == 'Q') return false;
            rt--;
            ct--;
        }
        
        //down-left diagnol
        rt = row;
        ct = col;
        while(rt<n && ct>=0){
            if(board[rt][ct] == 'Q') return false;
            rt++;
            ct--;
        }
        // left horizontal
        rt = row;
        ct = col;
        while(ct>=0){
            if(board[rt][ct] == 'Q') return false;
            ct--;
        }
        return true;
    }
    
    void solve(int col, int n, vector<string> &board){
        if(col == n){
            cnt++;
            return;
        }
        
        for(int row=0; row<n; row++){
            if(isSafe(row, col, n, board)){
                board[row][col] = 'Q';
                solve(col+1, n, board);
                board[row][col] = '.';
            }
        }
    }
public:
    int totalNQueens(int n) {

        vector<string> board(n);
        string s(n, '.');
        for(int i=0; i<n; i++){
            board[i] = s;
        }
        
        solve(0, n, board);
        return cnt;
    }
};