class TimeMap {
    struct Entry {
        int time;
        string value;
    };
    unordered_map<string, vector<Entry>> hashmap;

   public:
    TimeMap() {}

    void set(string key, string value, int timestamp) {
        hashmap[key].push_back({timestamp, value});
    }

    string get(string key, int timestamp) {
        auto it = hashmap.find(key);
        if (it == hashmap.end()) {return "";}
        vector<Entry>& entries = it->second;
        int lo = 0;
        const int n = static_cast<int>(entries.size());
        int hi = n;

        while (lo < hi) {
            int mid = lo + (hi - lo) / 2;
            if (entries[mid].time > timestamp) {hi = mid;}
            else {lo = mid + 1;}
        }
        return (lo != 0) ? entries[lo - 1].value : "";
    }
};
