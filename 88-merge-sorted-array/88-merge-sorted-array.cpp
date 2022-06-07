class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        // Two Pointers
        int tail1 = m-1, tail2 = n-1, fin = m+n-1;
        
        while(tail1 >= 0 && tail2 >= 0){
            if(nums1[tail1] <= nums2[tail2 ]) nums1[fin--] = nums2[tail2 --];
            else nums1[fin--] = nums1[tail1 --];
        }
        while(tail2 >= 0){
            nums1[fin--] = nums2[tail2--];
        }
    }
};