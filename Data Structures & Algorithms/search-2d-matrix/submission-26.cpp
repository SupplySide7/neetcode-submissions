class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        const int rows = static_cast<int>(matrix.size());
        const int cols = static_cast<int>(matrix[0].size());
        auto num = [&] (const int x) {return matrix[x/cols][x % cols];};
        const int n = rows * cols;
        int lo = 0, hi = n;
        while (lo < hi) {
            int mid = lo + (hi - lo)/2;
            if (num(mid) >= target) {hi = mid;}
            else {lo = mid + 1;}
        }
        return lo < n && num(lo) == target;
    }
};
