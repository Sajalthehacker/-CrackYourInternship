class MyHashSet {
private:
    vector<list<int>> m; 
    int size;
public:
    MyHashSet() {
        size = 100;
        m.resize(size);
    }
    int hash(int key) {
        return key%size;
    }
    
    list<int> :: iterator search(int key){
        int ind = hash(key);
        return find(m[ind].begin(), m[ind].end(), key);
    }
    
    
    void add(int key) {
        if(contains(key)) return;
        int ind = hash(key);
        m[ind].push_back(key);
    }
    
    void remove(int key) {
        if(!contains(key)) return;
        int ind = hash(key);
        m[ind].erase(search(key));
    }
    
    bool contains(int key) {
        int ind = hash(key);
        return (search(key) != m[ind].end());
    }
};

/**
 * Your MyHashSet object will be instantiated and called as such:
 * MyHashSet* obj = new MyHashSet();
 * obj->add(key);
 * obj->remove(key);
 * bool param_3 = obj->contains(key);
 */