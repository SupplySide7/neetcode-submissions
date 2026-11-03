class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        vector<int> *temp; temp = &temperatures;
        const int n = static_cast<int>((*temp).size());
        vector<int> result; result.resize(n);
        stack<pair<int, int>> stk;
        for (int i = 0; i < n; ++i) {
            while (!stk.empty() && (*temp)[i] > (stk.top()).second) {
                result[(stk.top()).first] = (i - (stk.top()).first);
                stk.pop();
            }
            stk.push({i, (*temp)[i]});
        } return result;
    }
};
