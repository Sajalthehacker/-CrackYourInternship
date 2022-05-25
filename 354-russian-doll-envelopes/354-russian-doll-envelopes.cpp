class Solution {
public:
    static bool cmp(const vector<int> &a , const vector<int> &b){
        if(a[0]==b[0]){
            return a[1]>b[1];
        }
        return a[0]<b[0];
    }

    int maxEnvelopes(vector<vector<int>>& arr) {
        sort(arr.begin(),arr.end(),cmp);
        int n=arr.size();

        vector<int> res;

        for(int i=0;i<n;i++){
            auto it=lower_bound(res.begin(),res.end(),arr[i][1]);
            if(it==res.end()) {
                res.push_back(arr[i][1]);
            } 
            else {
                *it=arr[i][1];
            }
        }
        return res.size();
    }
};
