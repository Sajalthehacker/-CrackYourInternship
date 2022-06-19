class Solution {
public:
    vector<vector<string>> suggestedProducts(vector<string>& products, string searchWord) {
        
        vector<vector<string>> ans;
        
        auto it = products.begin();
        sort(products.begin(), products.end());
        
        string curr = "";
        for(char ch : searchWord){
            vector<string> sugg;
            curr.push_back(ch);
            // Initialise pointer to lower bound
            it = lower_bound(it, products.end(), curr);
            // Iterate over next 3 pointers to get first 3 suggested words
            for (int i = 0; i < 3 && it + i != products.end(); i++) {
                string& s = *(it + i);
                if (s.find(curr)) break;
                sugg.push_back(s);
            }
            ans.push_back(sugg);
        }
        return ans;
    }
};