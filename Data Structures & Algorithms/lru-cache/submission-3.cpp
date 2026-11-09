class LRUCache {
private:
    struct Entry {int key; int val;};
    int capacity;
    list<Entry> ordered_list;
    unordered_map<int, list<Entry>::iterator> cache_map;
public:
    LRUCache(int capacity) : capacity(capacity) {}
    
    int get(int key) {
        if (auto it = cache_map.find(key); it != cache_map.end()) {
            auto node = it->second;
            int value = node->val;
            ordered_list.splice(ordered_list.begin(), ordered_list, node);
            return value;
        } else return -1;
    }
    
    void put(int key, int value) {
        if (auto it = cache_map.find(key); it != cache_map.end()) {
            auto node = it->second;
            node->val = value;
            ordered_list.splice(ordered_list.begin(), ordered_list, node);
            return;
        }
        if (static_cast<int>(ordered_list.size()) >= this->capacity) {
            cache_map.erase(ordered_list.back().key);
            ordered_list.pop_back();
        }
        ordered_list.push_front({key, value});
        cache_map[key] = ordered_list.begin();
        return;
    }
};
