class Solution {
public:
    int maxScore(vector<int>& cardPoints, int k) {
        int n = cardPoints.size();
        int sum = 0;
        for(int it : cardPoints){
            sum += it;
        }
        
        int window = 0;
        for(int i=0; i<n-k; i++){
            window += cardPoints[i];
        }
        int l=0, r=n-k-1;
        int maxi = sum - window;
        while(r<n-1){
            r++;
            window += (cardPoints[r]);
            window -= (cardPoints[l]);
            l++;
            
            maxi = max(maxi, sum-window);
        }
        
        return maxi;
        
    }
};