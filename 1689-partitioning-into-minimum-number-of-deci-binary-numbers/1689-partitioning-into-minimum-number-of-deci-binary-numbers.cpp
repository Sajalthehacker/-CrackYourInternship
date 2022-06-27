class Solution {
public:
    int minPartitions(string n) {
        char maxi = n[0];
        for(char it : n) maxi = max(maxi, it);
        return (maxi-'0');
    }
};