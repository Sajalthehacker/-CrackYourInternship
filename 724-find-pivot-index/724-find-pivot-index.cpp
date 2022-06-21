class Solution {
public:
    int pivotIndex(vector<int>& nums) {
        
        int n = nums.size();
        // Calculate the prefic sum of #nums
        vector<int> prefix;
        prefix.push_back(nums[0]);
        
        for(int i=1; i<n; i++)
            prefix.push_back(prefix[i-1] + nums[i]);
        
        for(int i=0; i<n; i++){
            int left, right;
            if(i == 0) left = 0; // if i is 0, there is no element on left
            else left = prefix[i-1];
            
            if(i == n-1) right = 0; // if i is n-1, there is no element on right
            else right = prefix[n-1] - prefix[i]; 
            
            if(left == right) return i;
        }
        return -1;; // No pivot found
    }
};