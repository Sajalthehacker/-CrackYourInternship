class Solution {
private:
    void dfs(int source, vector<bool> &vis, vector<vector<int>> &rooms){
        vis[source] = true;
        for(int it : rooms[source]){
            if(vis[it] == true) continue;
            dfs(it, vis, rooms);
        }
    }
public:
    bool canVisitAllRooms(vector<vector<int>>& rooms) {
        int n = rooms.size();
        vector<bool> vis(n, false);
        dfs(0, vis, rooms);
        // After this dfs if there is a key(edge) to every room,
        // By the end every room should be visited
        // If there is any room left unvisited, then impossible
        for(bool it : vis){
            if(it == false) return false;
        }
        return true;
    }
};