// Fast but size dependent
class MyHashSet {
private:
    vector<bool> v;
public:
    /** Initialize your data structure here. */
    MyHashSet() {
        v = vector<bool>(1000000, false);
    }
    
    void add(int key) {
        if(!v[key])
            v[key] = true;
    }
    
    void remove(int key) {
        if(v[key])
            v[key] = false;
    }
    
    /** Returns true if this set contains the specified element */
    bool contains(int key) {
        return v[key];
    }
};

/**
 * Your MyHashSet object will be instantiated and called as such:
 * MyHashSet* obj = new MyHashSet();
 * obj->add(key);
 * obj->remove(key);
 * bool param_3 = obj->contains(key);
 */
// Slow but robust for varying sizes
class MyHashSet {
    vector<int> v;
public:
    /** Initialize your data structure here. */
    MyHashSet() {
        
    }
    
    void add(int key) {
        if(!this->contains(key)) {
            v.push_back(key);
        }
    }
    
    void remove(int key) {
        int loc = 0, n = v.size();
        while(loc < n && v[loc] != key)
            loc++;
        if(loc < n) {
            v.erase(v.begin() + loc);
        }
    }
    
    /** Returns true if this set contains the specified element */
    bool contains(int key) {
        for(int i : v)
            if(i == key)
                return true;
        return false;
    }
};

/**
 * Your MyHashSet object will be instantiated and called as such:
 * MyHashSet* obj = new MyHashSet();
 * obj->add(key);
 * obj->remove(key);
 * bool param_3 = obj->contains(key);
 */