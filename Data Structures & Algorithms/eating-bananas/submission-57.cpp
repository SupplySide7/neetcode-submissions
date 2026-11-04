class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        auto time = [&] (const int k) {int hours = 0;
            for (const auto& bananas : piles) {hours += (bananas/k + (bananas % k != 0));} 
            return hours; };
        int lo = 1, n = ranges::max(piles), hi = n;
        while (lo < hi) {
            int med = lo + (hi - lo)/2;
            if (time(med) <= h) hi = med;
            else lo = med + 1;
        } return lo;
    }
};
