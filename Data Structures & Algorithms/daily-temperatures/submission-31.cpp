class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        auto& temp = temperatures;
        const int n = static_cast<int>(temp.size());
        vector<int> result(n, 0);
        vector<int> stck;
        for (int i = 0; i < n; ++i) {
            while (!stck.empty() && temp[i] > temp[stck.back()]) {
                result[stck.back()] = i - stck.back();
                stck.pop_back();
            }
            stck.push_back(i);
        }
        return result;   
    }
};
