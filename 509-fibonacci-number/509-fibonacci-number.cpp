class Solution {
public:
    int fib(int n) {
        if(n<2) return n;
        
        int prev = 0, curr = 1, next;
        for(int i=0; i<n-1; i++){
            next = prev + curr;
            prev = curr;
            curr = next;
        }
        return curr;
    }
};