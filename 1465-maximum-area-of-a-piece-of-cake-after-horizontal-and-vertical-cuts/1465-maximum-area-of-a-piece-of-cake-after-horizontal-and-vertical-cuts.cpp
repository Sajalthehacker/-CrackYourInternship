class Solution {
private:
    long long int mod = 1e9+7;
public:
    int maxArea(int h, int w, vector<int>& hor, vector<int>& ver) {
        
        sort(hor.begin(), hor.end());
        sort(ver.begin(), ver.end());

        int xd = max(hor[0], h-hor[hor.size()-1]);
        int yd = max(ver[0], w-ver[ver.size()-1]);
        
        for(int i=1; i<hor.size(); i++){
            xd = max(xd, hor[i]-hor[i-1]);
        }
        for(int i=1; i<ver.size(); i++){
            yd = max(yd, ver[i]-ver[i-1]);
        }
        
        return ((xd % mod)*(yd % mod) % mod);
    }
};