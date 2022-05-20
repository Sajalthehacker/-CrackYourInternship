class Solution {
public:
    int subarraysDivByK(vector<int>& nums, int k) {
        int pre = 0, total = 0;
        unordered_map<int, int> freq;
        freq[0] = 1;
        
        for(int i=0; i<nums.size(); i++){
            pre += nums[i];
            int rem = pre % k;
            if(rem < 0) rem += k;
            
            if(freq.find(rem)!=freq.end()){
                total += freq[rem];
                freq[rem]++;
            }
            else{
                freq[rem] = 1;
            }
        }
        return total;
    }
};