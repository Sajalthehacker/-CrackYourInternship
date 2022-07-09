class Solution {
public:
    int maxResult(vector<int>& nums, int k) {
        int n=nums.size();
        int score[n];
        priority_queue<pair<int, int>> dp;
        
        for(int i=n-1 ; i>=0 ; i--)
        {
            while(dp.size() && dp.top().second>i+k)
                dp.pop();
            
            score[i]=nums[i];
            score[i]+=(dp.size() ? dp.top().first : 0);
            dp.push({score[i], i});
        }
        
        return score[0];
    }
};