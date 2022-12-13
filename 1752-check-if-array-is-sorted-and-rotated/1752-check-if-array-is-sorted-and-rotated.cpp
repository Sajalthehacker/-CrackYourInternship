class Solution {
public:
    bool check(vector<int>& nums) {
        // if array is sorted it has all elements in order a[i]<=a[i+1]<=a[i+2]
        // if the array is rotated, then it has only one valley, i.e. a[i]>=a[i+1]<=a[i+2]
        int n = nums.size();
        int valleyCnt = 0;
        for(int i=0; i<n; i++){
            if(nums[i] > nums[(i+1)%n]) valleyCnt++;
        }
        return valleyCnt<=1;
    }
};