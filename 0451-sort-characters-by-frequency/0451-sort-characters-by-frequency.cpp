class Solution {
public:
    string frequencySort(string s) {
        map<char, int> freq;
        priority_queue<pair<int, char>> pq;
        for(char  it : s) freq[it]++;
        for(auto it : freq){
            pq.push({it.second, it.first});
        }
        s = "";
        while(!pq.empty()){
            char curr = pq.top().second;
            int t = pq.top().first;
            pq.pop();
            for(int i=0; i<t; i++) s.push_back(curr);
        }
        return s;
    }
};