class Solution {
private:
    int rec(int i, int j, int k, vector<int> &houses, vector<vector<int>> &cost, vector<vector<vector<int>>> &dp) {
        if (i < 0)
            return (k == 0) ? 0 : 100000000;
        if (k < 0)
            return 1e8;
        if (dp[i][j][k] != -1)
            return dp[i][j][k];
        // if house is already coloured
        if (houses[i])
            return dp[i][j][k] = rec(i - 1, houses[i], k - (houses[i] != j), houses, cost, dp);
        
        // if not coloured
        int res = 1e8;
        for (int l = 1; l <= cost[i].size(); l++)
            res = min(res, cost[i][l - 1] + rec(i - 1, l, k - (l != j), houses, cost, dp));
        
        return dp[i][j][k] = res;
    }
public:
    int minCost(vector<int>& houses, vector<vector<int>>& cost, int m, int n, int target) {
        swap(n, m);
        vector<vector<vector<int>>> dp(n, vector<vector<int>>(m + 1, vector<int>(target + 1, -1)));
        int res = rec(n - 1, 0, target, houses, cost, dp);
        return (res >= 1e8) ? -1 : res;
    }
};