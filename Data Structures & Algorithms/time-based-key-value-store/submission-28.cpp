class TimeMap {
private:
    struct Entry{int timestamp; string value;};
    unordered_map<string, vector<Entry>> hashmap;

public:    
    void set(string key, string value, int timestamp) {
        hashmap[key].push_back({timestamp, value});
    }
    
    string get(string key, int timestamp) {
        auto it = hashmap.find(key);
        if (it == hashmap.end()) {return "";}
        const vector<Entry>& entries = it->second;
        int lo = 0, hi = static_cast<int>(entries.size());
        while (lo < hi) {
            int mid = lo + (hi - lo)/2;
            if (entries[mid].timestamp > timestamp) {hi = mid;}
            else {lo = mid + 1;}
        }
        return lo == 0? "" : entries[lo - 1].value;
    }
};
