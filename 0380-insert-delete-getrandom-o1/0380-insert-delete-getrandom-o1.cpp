class RandomizedSet {
public:
    unordered_map<int, int> mpp;
    vector<int> arr;
    // int last;
    RandomizedSet() {
        // last = 0;
    }
    
    bool insert(int val) {
        if(mpp.find(val) != mpp.end()) return false;
        arr.push_back(val);
        mpp[val] = arr.size()-1;
        return true;
    }
    
    bool remove(int val) {
        if(mpp.find(val) == mpp.end()) return false;
        int lastEle = arr.back();
        arr[mpp[val]] = arr.back();
        arr.pop_back();
        mpp[lastEle] = mpp[val];
        mpp.erase(val);
        return true;
    }
    
    int getRandom() {
        // srand(time(0));
        return arr[rand() % arr.size()];
    }
};

/**
 * Your RandomizedSet object will be instantiated and called as such:
 * RandomizedSet* obj = new RandomizedSet();
 * bool param_1 = obj->insert(val);
 * bool param_2 = obj->remove(val);
 * int param_3 = obj->getRandom();
 */