class Solution {
public:
    int trap(vector<int>& height) {
        int n = height.size();
        // we consider how much amount of water every block contributes
        int ngr[n];
        for(int i=n-1; i>=0; i--){
            if(i == n-1) ngr[i] = height[i];
            else ngr[i] = max(ngr[i+1], height[i]);
        }
        int ngl[n];
        for(int i=0; i<n; i++){
            if(i == 0) ngl[i] = height[0];
            else ngl[i] = max(ngl[i-1], height[i]);
        }
        int total = 0;
        for(int i=0; i<n; i++){
            if(ngr[i] == -1 || ngl[i] == -1) continue;
            total += min(ngl[i], ngr[i])-height[i];
        }
        return total;
        
    }
};