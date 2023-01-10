class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        int slow = nums[0];
        int fast = nums[0];
        
        // run a loop untill slow and fast pointer meet at a point
        //Here we used a do-while loop coz, 
        //in first case slow == fast (both are nums[0]) 
        //but we have to move each of them atleast one time
        
        do{
            slow = nums[slow];
            fast = nums[nums[fast]];
        }while(slow != fast);
            
        //Once we get intersection point, According to floyd algo
        //if we move simultaneously from intrsection and start, 
        //both pointers will intersect at start of the cycle which is our answer
        
        slow = nums[0];
        while(slow != fast){
            slow = nums[slow];
            fast = nums[fast];
        }
        return slow;
    }
};