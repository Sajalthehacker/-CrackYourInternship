class Solution {
public:
    int hammingWeight(uint32_t n) {
        int count = 0;
        uint32_t dup = n;
        while(dup){
            count++;
            dup &= (dup-1);
        }
        return count;
    }
};