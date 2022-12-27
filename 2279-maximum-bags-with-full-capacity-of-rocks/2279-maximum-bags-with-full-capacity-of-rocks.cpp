class Solution {
public:
    int maximumBags(vector<int>& capacity, vector<int>& rocks, int ar) {
        int n = rocks.size();
        vector<int> rem(n, 0);
        
        for(int i=0; i<n; i++){
            rem[i] = capacity[i]-rocks[i];
        }
        sort(rem.begin(), rem.end());
        int cnt = 0;
        for(int i=0; i<n; i++){
            if(rem[i]==0) {
                cnt++;
                continue;
            }
            if(rem[i]<=ar){
                cnt++;
                ar -= rem[i];
            }else{
                break;
            }
        }
        return cnt;
    }
};