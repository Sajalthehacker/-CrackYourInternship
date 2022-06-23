class Solution {
private:
    // Comparator for sorting Courses according to their Dealines
    static bool comp(vector<int> &a, vector<int> &b){
        return a[1] < b[1];
    }
public:
    int scheduleCourse(vector<vector<int>>& courses) {
        sort(courses.begin(), courses.end(), comp);
        priority_queue<int> pque;
        
        int time = 0; // To determine the deadlines
        for(auto it : courses){
            time += it[0];
            pque.push(it[0]);
            if(time > it[1]){
                int prevLong = pque.top();
                time -= prevLong;
                pque.pop(); // Prevlongest task would be eliminated here
            }
        }
        return pque.size();
    }
};