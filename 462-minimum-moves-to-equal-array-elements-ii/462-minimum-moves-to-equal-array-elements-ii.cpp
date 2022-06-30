class Solution {
public:
    int minMoves2(vector<int>& nums) {
        // Create a prefix array of sorted nums
        int n = nums.size();
        sort(nums.begin(), nums.end());

        // Idea is to change all the numbers to median in the array
        int mini = 0;
        for(int i=0; i<n; i++){
            mini += abs(nums[i] - nums[n/2]);
        }
        return mini;
    }
};