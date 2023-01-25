class Solution {
public:
    bool isHappy(int n) {
        // Use linkedlist cycle method : Slow-Fast Pointers
        // 19 -> 82 -> 68 -> 100 -> 1
        // 89 -> 145 -> 42 -> 20 -> 4 -> 16 -> 37 -> 58 -> 89
        // For 89 if we observe we are getting a cycle, 
        //so through slow-fast pointer method if we could say that 
        //if there is any cycle involved in simulation, it's not a happy number
        
        int slow = n, fast = n;
        do{
            slow = digSum(slow); // Moves one step
            fast = digSum(digSum(fast)); // Moves 2 steps
        }
        while(slow != fast);
        
        return slow == 1;
    }
    
    int digSum(int num){
        int newNum = 0;
        while(num>0){
            int digit = num%10;
            newNum += (digit * digit);
            num /= 10;
        }
        return newNum;
    }
};