class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        const int max_k = ranges::max(piles);
        auto time_elapsed = [&] (const int k) {
            int hours = 0;
            for (const int bananas : piles) {
                hours += bananas/k + ((bananas % k) != 0);
            } return hours;};
        int lo = 1, hi = max_k;
        while (lo < hi) {
            int mid = lo + (hi - lo)/2;
            if (time_elapsed(mid) <= h) hi = mid;
            else lo = mid + 1;
        } return lo;
    }
};
