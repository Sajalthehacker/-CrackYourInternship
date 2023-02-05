class Solution {
public:
    int majorityElement(vector<int>& nums) {
        
        int cnt = 0 , ele;
        for(int it : nums){
            if(cnt == 0) {
                ele = it;
                cnt++;
            }
            else if(it == ele) cnt++;
            else cnt--;
        }
        return ele;
    }
};