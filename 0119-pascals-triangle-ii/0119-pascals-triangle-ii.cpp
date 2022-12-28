class Solution {
public:
    vector<int> getRow(int r) {
        // dp 
        vector<int> row(r+1, 0);
        row[0] = 1;
        for(int i=0; i<=r; i++){
            for(int j=i; j>0; j--)
                row[j] = row[j] + row[j-1];
        }
        return row;
    }
};