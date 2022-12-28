class Solution {
public:
    int minStoneSum(vector<int>& piles, int k) {
        priority_queue<int> pque;
        int total = 0;
        for(int i=0; i<piles.size(); i++){
            total += piles[i];
            pque.push(piles[i]);
        }
        for(int i=0; i<k; i++){
            int curr = pque.top();
            pque.pop();
            pque.push(curr - curr/2);
            total -= curr/2;
        }
        return total;
    }
};