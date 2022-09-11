class Solution {
private:
    bool check(int div, int threshold, vector<int> &nums){
        int sum = 0;
        for(int it : nums){
            sum += ceil(it*(1.0)/div);
        }
        return sum <= threshold;
    }
public:
    int smallestDivisor(vector<int>& nums, int threshold) {
        // MnFn : (We get the largest value at 1)F F F F F T T T T T T T(smallest value at end)
        // least true is needed divisor
        int start = 1, end = INT_MAX, mid;
        
        while(end - start > 1){
            mid = start + (end - start) / 2;
            
            if(check(mid, threshold, nums)){
                end = mid;
            }
            else start = mid + 1;
        }
        if(check(start, threshold, nums)) return start;
        else return end;
    }
};