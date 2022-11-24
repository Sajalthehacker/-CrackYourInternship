class Solution {
private:
    int n, m;
    bool search(int ind, int i, int j, string &word, vector<vector<bool>> &vis, vector<vector<char>>& board){
        if(ind == word.length()-1) return true;
        
        vis[i][j] = true;
        if(i>0 && !vis[i-1][j] && board[i-1][j] == word[ind+1] && search(ind+1, i-1, j, word, vis, board)) return true;               if(j>0 && !vis[i][j-1] && board[i][j-1] == word[ind+1] && search(ind+1, i, j-1, word, vis, board)) return true;
        if(i<n-1 && !vis[i+1][j] && board[i+1][j] == word[ind+1] && search(ind+1, i+1, j, word, vis, board)) return true;
        if(j<m-1 && !vis[i][j+1] && board[i][j+1] == word[ind+1] && search(ind+1, i, j+1, word, vis, board)) return true;
        vis[i][j] = false;
        return false;
    }
        
public:
    bool exist(vector<vector<char>>& board, string word) {
        n = board.size();
        m=board[0].size();
        vector<vector<bool>> vis(n, vector<bool>(m, false));
        
        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                if(board[i][j] == word[0] && search(0, i, j, word, vis, board)) return true;
            }
        }
        return false;
    }
};