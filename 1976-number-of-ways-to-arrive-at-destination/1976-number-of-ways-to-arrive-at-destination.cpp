class Solution {
public:
    int countPaths(int n, vector<vector<int>>& roads) {
        vector<pair<long long, long long>> adj[n];
        for(auto edge : roads){
            adj[edge[0]].push_back({edge[1], edge[2]});
            adj[edge[1]].push_back({edge[0], edge[2]});
        }
        vector<long long> time(n, 1e18);
        vector<long long> ways(n, 0);
        
        long long ans = 0, prevTime = 1e18;
        // pque = {time, node}
        priority_queue<pair<long long, long long>, 
            vector<pair<long long, long long>>, 
            greater<pair<long long, long long>>> pque;
        pque.push({0, 0});
        time[0] = 0;
        ways[0] = 1;

        while(!pque.empty()){
            auto curr = pque.top();
            pque.pop();
            long long currTime = curr.first, currNode = curr.second; 

            for(auto next : adj[currNode]){
                int nextNode = next.first, nextWeight = next.second;

                if(currTime + nextWeight < time[nextNode]){
                    time[nextNode] = currTime + nextWeight;
                    pque.push({currTime + nextWeight, nextNode});
                    ways[nextNode] = ways[currNode];
                }
                else if(currTime + nextWeight == time[nextNode]){
                    ways[nextNode] = (ways[nextNode] + ways[currNode]) % 1000000007;

                }
            }

        }
        return ways[n-1] % 1000000007;
    }
};