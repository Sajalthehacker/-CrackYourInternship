class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        // make adj list
        vector<pair<int, int>> adj[n+1];
        for(auto edge : times){
            adj[edge[0]].push_back({edge[1], edge[2]});
        }
        
        // Dijkstra's Algo
        vector<int> time(n+1, 1e9);
        vector<bool> vis(n+1, false);

        // pque = {time, node}
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pque;
        pque.push({0, k});
        time[k] = 0;
        time[0] = -1; // 1 based indexing
        while(!pque.empty()){
            auto curr = pque.top();
            pque.pop();
            int currTime = curr.first, currNode = curr.second; 
            // if(vis[currNode]) continue;
            // vis[currNode] = true;
            
            for(auto next : adj[currNode]){
                int nextNode = next.first, nextWeight = next.second;
                if(currTime + nextWeight < time[nextNode]){
                    time[nextNode] = currTime + nextWeight;
                    pque.push({currTime + nextWeight, nextNode});
                }
            }
        }
        int ans = -1;

        for(int it : time) ans = max(ans , it);
        return (ans == 1e9) ? -1 : ans;
    }
};