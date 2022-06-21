class Solution {
public:
    vector<int> findSmallestSetOfVertices(int n, vector<vector<int>>& edges) {
        
        // Here the ans would be all the nodes, without incoming edges
        // Observation :
        // All the nodes having incoming edge, can be visited from a souce node
        // And that doesn't have incoming edge
        
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