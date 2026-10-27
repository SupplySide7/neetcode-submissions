class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        const int n = ranges::max(piles);
        auto elapsed_time = [&] (int k) {
            int hours = 0;
            for (const int& bananas : piles)
            {hours += bananas/k + ((bananas % k) != 0);}
            return hours;};
        
        int lo = 1; // eat at least 1 banana per hour, zero would not eat at all
        int hi = n; // at k = n speed, each pile takes 1 hour to eat, or n sum hours
                    // and since hours, h >= n, n speed always satifies sum hours < h
        while (lo < hi) {
            int mid = lo + (hi - lo)/2;
            if (elapsed_time(mid) <= h) {hi = mid;}
            else {lo = mid + 1;}
        }
        return lo;
    }
};
