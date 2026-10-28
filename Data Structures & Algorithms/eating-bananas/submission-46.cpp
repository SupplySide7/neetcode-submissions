class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        int hi = ranges::max(piles);
        int lo = 1; // we must eat, can't be zero
        auto time_elapsed = [&] (const int k) {
            int hours = 0;
            for (const int bananas : piles) {
                hours += bananas/k + ((bananas % k) != 0);
            } return hours;
        };
        while (lo < hi) {
            int mid = lo + (hi - lo)/2;
            if (time_elapsed(mid) <= h) {hi = mid;}
            else {lo = mid + 1;}
        }return lo;
    }
};
