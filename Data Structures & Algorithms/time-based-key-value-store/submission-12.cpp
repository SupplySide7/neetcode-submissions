class TimeMap {
public:
    TimeMap() {}
    
    void set(string key, string value, int timestamp) {
        hashmap[key].emplace_back(timestamp, value);
    }
    
    string get(string key, int timestamp) {
        vector<pair<int, string>> &found = hashmap[key];
        int n = found.size() - 1;

        int left = 0;
        int right = n;
        string result = "";

        while (left <= right) {
            int midpoint = left + (right - left)/2;

            if (found[midpoint].first > timestamp) {
                right = midpoint - 1;
            }
            else { //found[midpoint].first <= timestamp
                result = found[midpoint].second;
                left = midpoint + 1;
            }
        }
        return result;
    }

private:
    unordered_map<string, vector<pair<int, string>>> hashmap;
};