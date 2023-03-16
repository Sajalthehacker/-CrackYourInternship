class Solution {
public:
    int majorityElement(vector<int>& nums) {
        // https://www.youtube.com/watch?v=AoX3BPWNnoE&list=PLgUwDviBIf0rPG3Ictpu74YWBQ1CaBkm2&index=17
        
        
        // Moore's Algo
        int cnt = 0 , ele;
        for(int it : nums){
            if(cnt == 0){
                ele = it;
            }
            if(it == ele) cnt++;
            else cnt--;
        }
        return ele;
    }
};