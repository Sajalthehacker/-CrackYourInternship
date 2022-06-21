class Solution {
public:
    vector<int> findSmallestSetOfVertices(int n, vector<vector<int>>& edges) {
        vector<bool> vis(n, false);
        for(auto it : edges){
            vis[it[1]] = true;
        }
        
        vector<int> ans;
        for(int i=0; i<n; i++){
            if(!vis[i]) ans.push_back(i);
        }
        return ans;
    }
};