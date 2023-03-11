class Solution {
public:
    int findPeakElement(vector<int>& arr) {
        if(arr.size() == 1) return 0;
        int start = 0, end = arr.size()-1, mid;
        while(start <= end){
            mid = start + (end - start) / 2;
            if(mid == 0){
                if(arr[mid] > arr[mid+1]) return mid;
                else start = mid+1;
            } 
            else if(mid == arr.size()-1){
                if(arr[mid] > arr[mid-1]) return mid;
                else end = mid - 1;
            }
            else{
                if(arr[mid] > arr[mid+1] && arr[mid] > arr[mid-1]) return mid;
                else{
                    if(arr[mid] < arr[mid+1]) start = mid+1;
                    else end = mid - 1;
                }
            }
        }
        return -1;
    }
};