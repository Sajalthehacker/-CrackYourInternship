class Solution {
public:
    void sortColors(vector<int>& arr) {
        int i=0, j=0, k=arr.size()-1;
        
        while(j<=k){
            switch(arr[j]){
                case 0:
                    swap(arr[i++], arr[j++]);
                    break;
                case 1:
                    j++;
                    break;
                case 2:
                    swap(arr[k--], arr[j]);
                    break;
            }
        }
    }
};