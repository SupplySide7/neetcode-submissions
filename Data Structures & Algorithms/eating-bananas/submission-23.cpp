class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        int k = 1;
        auto hours = [&] (int k) {long long time = 0;
            for (const int& p : piles) {time += p/k + ((p % k) != 0);}
            return time;};
        int lo = 1;
        long long hi = ((ranges::max(piles) * static_cast<long long>(piles.size())) / h) + 1;
        //int hi = ranges::max(piles);

        while (lo < hi) {
            int mid = lo + (hi - lo)/2;
            if (hours(mid) <= h) {hi = mid;} // mid is true: answer is mid or left of it
            else {lo = mid + 1;} // mid is false: answer is right of mid
        }
        return lo;
    }
};
