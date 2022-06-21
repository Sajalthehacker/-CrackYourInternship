class Solution {
public:
    int findCenter(vector<vector<int>>& edges) {
        // Observation :
        // Star node should be present in every edge,
        // So it would be any of the node in first pair
        
        if(edges[0][0] == edges[1][0] || edges[0][0] == edges[1][1]){
            // here e[0][0] is common so this is Star Node
            return edges[0][0];
        }
        else return edges[0][1];
    }
};