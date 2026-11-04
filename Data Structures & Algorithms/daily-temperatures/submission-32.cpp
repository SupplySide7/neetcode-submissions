class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        auto& temp = temperatures;
        const int n = temp.size();
        vector<int> result(n, 0);
        stack<int> stk;
        for (int i = 0; i < n; ++i) {
            while (!stk.empty() && temp[i] > temp[stk.top()]) {
                result[stk.top()] = i - stk.top();
                stk.pop();
            }
            stk.push(i);
        } return result;
    }
};
