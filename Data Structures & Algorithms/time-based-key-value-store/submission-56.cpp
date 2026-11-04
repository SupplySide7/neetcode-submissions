class TimeMap {
private:
    struct Entry {int time; string val;};
    unordered_map<string, vector<Entry>> hashmap;
public:
    void set(string key, string value, int timestamp) {
        hashmap[key].push_back({timestamp, value});
    }
    
    string get(string key, int timestamp) {
        if (auto it = hashmap.find(key); it == hashmap.end()) return "";
        else {
            const auto& [k, entries] = *it;
            const int n = entries.size();
            int lo = 0, hi = n;
            while (lo < hi) {
                int med = lo + (hi - lo)/2;
                if (entries[med].time > timestamp) hi = med;
                else lo = med + 1;
            } return lo != 0? entries[lo - 1].val : "";
        }
    }
};
