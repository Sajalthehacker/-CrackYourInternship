class Solution {
public:
    int sumSubarrayMins(vector<int>& arr) {
        // Find next smaller elemnts index to left and right
        long long n = arr.size();
        vector<long long> nsl(n, -1);
        vector<long long> nsr(n, -1);
        stack<long long> stk1;
        for(long long i=0; i<n; i++){
            while(!stk1.empty() && arr[stk1.top()] >= arr[i]){
                stk1.pop();
            }
            if(stk1.empty()) nsl[i] = -1;
            else nsl[i] = stk1.top();
            
            stk1.push(i);
        }
        stack<long long> stk2;
        for(long long i=n-1; i>=0; i--){
            while(!stk2.empty() && arr[stk2.top()] > arr[i]){
                stk2.pop();
            }
            if(stk2.empty()) nsr[i] = n;
            else nsr[i] = stk2.top();
            
            stk2.push(i);
        }
        
        for(int it : nsl) cout << it << " " ;
        cout << endl;
        for(int it : nsr) cout << it << " " ;
        cout << endl;
        
        
        long long ans = 0, mod = 1e9 + 7;
        for(long long i=0; i<n; i++){
            ans = (ans + (arr[i]*(i - nsl[i])*(nsr[i] - i) )) % mod;
        }
        return ans;
    }
};