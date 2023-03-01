class Solution {
public:
    int cnt = 0;

    void merge(int l, int mid, int r, vector<int> &nums){
        if(l>=r) return;
        vector<int> sortedArray(r-l+1);
        int ind1 = l, ind2 = mid+1, tind=0;
        while(ind1<=mid && ind2<=r){
            if(nums[ind1] < nums[ind2]) sortedArray[tind++] = nums[ind1++];
            else sortedArray[tind++] = nums[ind2++];
        }
        while(ind1<=mid) sortedArray[tind++] = nums[ind1++];
        while(ind2<=r)  sortedArray[tind++] = nums[ind2++];

        for(int i=0; i<r-l+1; i++) 
            nums[l+i] = sortedArray[i];
    }
    
    void mergeSort(int l, int r, vector<int> &nums){
        if(l>=r) return;
        
        int mid = l + (r-l)/2;
        mergeSort(l, mid, nums);
        mergeSort(mid+1, r, nums);
        merge(l, mid, r, nums);
    }
    
    vector<int> sortArray(vector<int>& nums) {
        mergeSort(0, nums.size()-1, nums);
        return nums;
    }
};