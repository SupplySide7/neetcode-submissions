class LRUCache {
private:    struct Entry {int key; int value;}; list<Entry> ordered;
            unordered_map<int, list<Entry>::iterator> cache;
            int capacity;
public:
    LRUCache(int capacity) : capacity(capacity) {}
    
    int get(int key) {
        if(auto it = cache.find(key); it != cache.end()) {
            auto node = it->second; int value = node->value;
            ordered.splice(ordered.begin(), ordered, node);
            return value;
        } return -1;
    }
    
    void put(int key, int value) {
        if(auto it = cache.find(key); it != cache.end()) {
            auto node = it->second; node->value = value;
            ordered.splice(ordered.begin(), ordered, node);
            return;
        }
        if (static_cast<int>(ordered.size()) == capacity) {
            cache.erase(ordered.back().key);
            ordered.pop_back();
        }
        ordered.push_front({key, value});
        cache[key] = ordered.begin();
    }
};
