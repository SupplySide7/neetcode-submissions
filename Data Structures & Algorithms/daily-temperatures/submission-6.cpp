class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        const int n = static_cast<int>(temperatures.size());
        vector<int> result(n, 0);
        vector<int> stck;
        for (int i = 0; i < n; ++i) {
            while (!stck.empty() && temperatures[i] > temperatures[stck.back()]) {
                result[stck.back()] = i - stck.back();
                stck.pop_back();
            }
            stck.push_back(i);
        }
        return result;   
    }
};
