class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        const int n = static_cast<int>(temperatures.size());
        vector<int> result(n, 0);
        vector<pair<int, int>> stck;
        for (int i = 0; i < n; ++i) {
            while (!stck.empty() && temperatures[i] > stck.back().second) {
                result[stck.back().first] = i - stck.back().first;
                stck.pop_back();
            }
            stck.push_back({i, temperatures[i]});
        }
        return result;   
    }
};
