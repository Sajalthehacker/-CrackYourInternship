class Solution {
public:
    int findCenter(vector<vector<int>>& edges) {
        int n = edges.size()+1;
        vector<int> degree(n+1, 0);
        
        int posNode = -1; //for storing nodes with degree 2
        
        for(auto it : edges){
            degree[it[0]]++;
            degree[it[1]]++;
            
            if(degree[it[0]] >= 3) return it[0]; // We found Star Node, which have degree 3
            else if(degree[it[0]] == 2) posNode = it[0]; // If not 3, starnode's degree ll be 2
            
            if(degree[it[1]] >= 3) return it[1];
            else if(degree[it[1]] == 2) posNode = it[1];
        }

        return posNode;
    }
};