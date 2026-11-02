class LRUCache {
private:
    vector<pair<int,int>>cache;
    int capacity;

public:
    LRUCache(int capacity) {
        this->capacity=capacity;
    }

    int get(int key) {
        for(int i=0;i<cache.size();i++) {
            if(cache[i].first==key) {
                pair<int,int>tmp=cache[i];
                cache.erase(cache.begin()+i);
                cache.push_back(tmp);
                return tmp.second;
            }
        }
        return -1;
    }

    void put(int key,int value) {
        for(int i=0;i<cache.size();i++) {
            if(cache[i].first==key) {
                cache.erase(cache.begin()+i);
                cache.push_back({key, value});
                return;
            }
        }

        if (cache.size()==capacity) {
            cache.erase(cache.begin());
        }

        cache.push_back({key,value});
    }
};
/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */