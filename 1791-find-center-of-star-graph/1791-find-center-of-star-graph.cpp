class Solution {
public:
    int findCenter(vector<vector<int>>& edges) {
        // vertex nde will be present in all the edges
        if(edges[0][0] == edges[1][0] || edges[0][0] == edges[1][1]) return edges[0][0];
        else return edges[0][1];
    }
};