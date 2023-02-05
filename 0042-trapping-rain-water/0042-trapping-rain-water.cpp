class Solution {
public:
    int trap(vector<int>& height) {
        int n = height.size();
        // we consider how much amount of water every block contributes
        int suffMax[n], prefMax[n];
        for(int i=n-1; i>=0; i--){
            if(i == n-1) suffMax[i] = height[i];
            else suffMax[i] = max(suffMax[i+1], height[i]);
        }
        for(int i=0; i<n; i++){
            if(i == 0) prefMax[i] = height[0];
            else prefMax[i] = max(prefMax[i-1], height[i]);
        }
        int total = 0;
        for(int i=0; i<n; i++)
            total += min(prefMax[i], suffMax[i])-height[i];
        
        return total;
    }
};