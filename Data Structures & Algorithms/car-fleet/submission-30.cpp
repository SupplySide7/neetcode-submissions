#include <ranges>
class Solution {
public:
    int carFleet(int target, vector<int>& position, vector<int>& speed) {
        vector<pair<double, double>> cars;
        for (const auto& [pos, spd] : ranges::views::zip(position, speed)) {
            cars.push_back({pos, spd});
        }
        ranges::sort(cars, greater{});
        stack<double> stk;
        for (const auto& [pos, spd] : cars) {
            double time = static_cast<double>((target - pos)/spd);
            if (stk.empty() || time > stk.top()) {stk.push(time);}
        } return stk.size();
    }
};
