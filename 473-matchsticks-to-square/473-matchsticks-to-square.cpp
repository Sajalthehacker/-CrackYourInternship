class Solution {
private:
    long long sum = 0, len;
    bool dfs(int ind, vector<int>& dir, vector<int>& match){
        if(ind == match.size()){
            if(dir[0] == dir[1] && dir[1] == dir[2] && dir[2] == dir[3]) return true;
        }
        
        for(int i=0; i<4; i++){
            if(dir[i] + match[ind] <= len){
                dir[i] += match[ind];
                if(dfs(ind+1, dir, match)){
                    return true;
                }
                dir[i] -= match[ind];
            }
        }
        return false;
    }
public:
    bool makesquare(vector<int>& match) {
        
        for(int it : match) sum += it;
        if(sum % 4) return false;
        len = sum/4;
        
        sort(match.begin(), match.end(), greater<int>());
        vector<int> dir(4, 0);
        return dfs(0, dir, match);
    }
};