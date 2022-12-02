class Solution {
public:
    bool closeStrings(string word1, string word2) {
        if(word1.size() != word2.size()) return false;
        int n = word1.size();
        vector<int> mpp1(26, 0), mpp2(26, 0);
        for(char it : word1) mpp1[it - 'a']++;
        for(char it : word2) {
            if(mpp1[it - 'a'] == 0) return false;
            mpp2[it - 'a']++;
        }
        sort(mpp1.begin(), mpp1.end());
        sort(mpp2.begin(), mpp2.end());

        for(int it : mpp1) cout << it << " ";
        cout << endl;
        for(int it : mpp2) cout << it << " ";
        cout << endl;
        
        for(int i=0; i<26; i++)
            if(mpp1[i] != mpp2[i]) return false;
        
        return true;
    }
};