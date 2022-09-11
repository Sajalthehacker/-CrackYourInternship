class Solution {
private:
    bool check(int maxSum, int m, vector<int> nums){
        int sum = 0, cnt = 1;
        
        for(int it : nums){
            if(it > maxSum) return false;
            
            if(sum + it > maxSum){
                cnt++;
                sum = it;
            }   
            else{
                sum += it;
            }
        }

        
        return cnt <= m;
        
    }
public:
    int splitArray(vector<int>& nums, int m) {
        // Here we can BS on val("Max value that a subArray can hold")
        // MnFn : F F F F T T T T T -> we need to fing first T with no of m subArrays
        
        int start = 0, end = INT_MAX, mid;
        
        while(end - start > 1){
            mid = start + (end - start) / 2;
            
            if(check(mid, m, nums)){
                end= mid;
            }
            else start = mid + 1;
        }
        cout << start << " " << end << endl;
        if(check(start, m, nums)) return start;
        else return end;
    }
};