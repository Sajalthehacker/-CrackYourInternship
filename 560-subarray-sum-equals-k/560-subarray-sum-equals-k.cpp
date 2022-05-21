class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        int cnt = 0;
        unordered_map<int, int> mpp;
        
        int pre = 0;
        mpp[0] = 1;
        
        for(int it : nums){
            pre += it; 
            if(mpp.find(pre-k)!=mpp.end()){
                // cout<<pre<<" "<<it<<" "<<pre-it<<endl;
                cnt += mpp[pre-k];
            }
            mpp[pre]++;
        }
        return cnt;
    }
};