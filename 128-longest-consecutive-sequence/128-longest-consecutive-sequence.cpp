class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        if(nums.size()==0) return 0;
        
        unordered_set<int> mpp(nums.begin(), nums.end());
        int cnt=1, ans=1;

        for(auto it : mpp){
            if(mpp.find(it-1)==mpp.end()){
                cnt = 1;
                while(mpp.find(it+cnt)!=mpp.end()){
                    cnt++;
                ans = max(ans, cnt);
                    
                }
            }
        }
        return ans;
    }
};