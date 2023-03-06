class Solution {
public:
    int findKthPositive(vector<int>& arr, int k) {
        // Given array : 2 3 4 7 11, if its complete array it would be : 1 2 3 4 5
        // if we do this : (arr[i] - i - 1) we get no. of ele missing before it
        // for given array, missEle array would be : 1 1 1 3 6, i.e before every arr[i], there are missEle[i] ele's missing
        // We dont actually needto create another array for ot, as we can get it by operation
        
        int n = arr.size();
        int start = 0, end = n-1, mid;
        
        while(end- start > 1){
            mid = start + (end - start) / 2;
            
            if(arr[mid] - mid - 1 >= k){
                end = mid;
            }
            else start = mid + 1;
        }
        
        if(arr[start] - start - 1 >= k) {
            return arr[start] - (arr[start] - start - k);
        }
        else if(arr[end] - end - 1 >= k) return arr[end] - (arr[end] - end - k);
        else return arr[n-1] + k - (arr[n-1] - n);
    }
};