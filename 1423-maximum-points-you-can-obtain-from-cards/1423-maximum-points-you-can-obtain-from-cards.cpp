class Solution {
public:
    int maxScore(vector<int>& cardPoints, int k) {
        // Application of Sliding Window & Prefix Sum
        // We have to find min sum subarray of length (n-k) & subtract it from total sum
        int n = cardPoints.size();
        int miniSum, totalSum = 0, preSum = 0;
        
        for(int i=0; i<n-k; i++){
            preSum += cardPoints[i];
            totalSum += cardPoints[i]; 
        }
        miniSum = preSum;
        int l = 0, r = n-k-1;
        
        while(r+1 < n){
            r++;
            totalSum += cardPoints[r];
            preSum += cardPoints[r];
            preSum -= cardPoints[l];
            l++;
            
            miniSum = min(miniSum, preSum);
        }
        return totalSum - miniSum;
    }
};