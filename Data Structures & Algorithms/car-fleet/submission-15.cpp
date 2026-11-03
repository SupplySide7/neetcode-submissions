#include <ranges>
class Solution {
public:
    int carFleet(int target, vector<int>& position, vector<int>& speed) {
        vector<pair<double, double>> cars; vector<double> fleet;
        for (const auto& [pos, speed] : ranges::views::zip(position, speed)) {
            cars.push_back({pos, speed});
        }
        ranges::sort(cars, greater{});
        for (const auto& [pos, speed] : cars) {
            if (double time = (target - pos)/speed; fleet.empty() || time > fleet.back()) {
                fleet.push_back(time);
            }
        } return fleet.size();
    }
};
