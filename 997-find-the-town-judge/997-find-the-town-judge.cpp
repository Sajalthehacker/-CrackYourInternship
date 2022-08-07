class Solution {
public:
    int findJudge(int n, vector<vector<int>>& trust) {
        vector<int> in(n, 0);
        
        for(auto it : trust){
            // Person 'a' trusts Person 'b'
            int a = it[0], b = it[1];
            // Count incoming and outgoing edges of the Graph
            in[a-1] = -1;
            if(in[b-1] != -1) in[b-1]++;
            
        }
        for(int i=0; i<n; i++){
            if(in[i] == n-1) return i+1;
        }
        return -1;

    }
};