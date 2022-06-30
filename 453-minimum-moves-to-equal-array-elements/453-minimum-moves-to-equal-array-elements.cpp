class Solution {
public:
    int minMoves(vector<int>& nums) {
        // Observation 1 : 
        // Adding 1 to n-1 the elements is equivalent to Subtracting 1 from remaining element, 
        // i.e  arr : 1 2 3 4, if we add 1 to 1st 3 ele arr : 2 3 4 4, if sub arr : 1 2 3 3
        // In terms of equalling al the elements {2,3,4,4 } & {1,2,3,3} represent same;
        
        // Observation 2 :
        // Asour approach is decrementin 1 from ele, we will equal the arr to min element
        
        // Finding min element:
        int mini = INT_MAX, ans = 0;
        for(int it : nums) mini = min(mini,  it);
        
        for(int it : nums) 
            ans += abs(it - mini);
        
        return ans;
    }
};