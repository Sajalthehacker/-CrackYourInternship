class LRUCache {
public:
    // https://www.youtube.com/watch?v=nN36SSIMn1k
    
    map<int, int> mpp; // for storing key-value pairs
    list<int> dll; // for storing order of recent used keys, front is most recent
    map<int, list<int>:: iterator> address; // for address of key in DLL;
    
    int size, cap;
    LRUCache(int capacity) {
        cap = capacity;
        size = 0;
    }
    
    int get(int key) {
        if(mpp.find(key) == mpp.end()) return -1; // Key not present
        list<int>:: iterator it = address[key];
        dll.erase(it);
        dll.push_front(key);
        address[key] = dll.begin();
        return mpp[key];
    }
    
    void put(int key, int value) {
        if(mpp.find(key) != mpp.end()){
            mpp.erase(key);
            list<int>:: iterator it = address[key];
            dll.erase(it);
            address.erase(key);
            size--;
        }
        if(size == cap){
            int lastEle = dll.back();
            dll.pop_back();
            mpp.erase(lastEle);
            address.erase(lastEle);
            size--;
        }
        mpp[key] = value;
        dll.push_front(key);
        address[key] = dll.begin();
        size++;
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */