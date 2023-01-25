class Solution {
public:
    bool isHappy(int n) {
        // Use linkedlist cycle method : Slow-Fast Pointers
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