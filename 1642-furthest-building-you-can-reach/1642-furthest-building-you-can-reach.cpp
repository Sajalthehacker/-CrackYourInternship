class Solution {
public:
    int furthestBuilding(vector<int>& heights, int bricks, int ladders) {
        priority_queue<int> maxJumps;
        
        int n = heights.size(), i;
        for(i=1; i<n; i++){
            if(heights[i] <= heights[i-1]) continue;
            int jump = heights[i] - heights[i-1];
            maxJumps.push(jump);
            
            bricks -= jump;
            if(bricks < 0){
                // We are taking back the brics from prev highest block
                // And add a ladder over there
                bricks += maxJumps.top();
                maxJumps.pop();
                // If we dont have a ladder available, 
                // It's impossible to climb this cliff
                if(ladders <= 0) break; 
                ladders--;
            }
        }
        return i-1;
    }
};