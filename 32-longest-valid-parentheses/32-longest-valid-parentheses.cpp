class Solution {
public:
    int longestValidParentheses(string s) {
        //Solution with O(1) Space Complexity
            
        int open = 0, close = 0;
        int n = s.length();
        int maxi = 0;
        
        // From left to right
        for(int i=0; i<n; i++){
            char c = s[i];
            // Maintain the count of open and close brackets
            if(s[i] == '(') open++;
            else close++;
            
            // Assumption
            // anytime close brackets shouldn't be greater than open brackets
            
            if(open == close){
                int len = open + close;
                maxi = max(maxi, len);
            }else if(open < close){
                open = close = 0;
            }
        }
        open = 0;
        close = 0;

        
        // From right to left
        for(int i=n-1; i>=0; i--){
            char c = s[i];
            // Maintain the count of open and close brackets
            if(s[i] == '(') open++;
            else close++;
            
            // Assumption
            // anytime close brackets shouldn't be greater than open brackets
            
            if(open == close){
                int len = open + close;
                maxi = max(maxi, len);
            }else if(close < open){
                open = close = 0;
            }
        }
        
        return maxi;
    }
};