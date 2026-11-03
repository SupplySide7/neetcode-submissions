#include <ranges>
class Solution {
public:
    int carFleet(int target, vector<int>& position, vector<int>& speed) {
        vector<pair<double, double>> cars;
        stack<double> stk;
        for (const auto& [pos, spd] : ranges::views::zip(position, speed)) {
            cars.push_back({pos, spd});
        } ranges::sort(cars, greater{});
        for (const auto& [pos, spd] : cars) {
            
            if (const double time = static_cast<double>((target - pos)/spd); stk.empty() || 
                time > stk.top()) stk.push(time); 
        } return stk.size();
    }
};
