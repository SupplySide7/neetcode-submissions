class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        auto time = [&] (int k) {
            long long hours = 0;
            for (const int bananas : piles)
                hours += bananas/k + ((bananas % k) != 0);
            return hours;};
        
        int lo = 1;
        int hi = ranges::max(piles);
        while (lo < hi) {
            int mid = lo + (hi - lo)/2;
            if (time(mid) <= h) {hi = mid;}
            else {lo = mid + 1;}
        }
        return lo;
    }
};
