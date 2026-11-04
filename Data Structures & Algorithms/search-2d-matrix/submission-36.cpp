class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        const int rows = matrix.size();
        const int cols = matrix[0].size();
        const auto& num = [&] (const int x) {return matrix[x/cols][x % cols];};
        int lo = 0, n = rows * cols, hi = n;
        while (lo < hi) {
            int median = lo + (hi - lo)/2;
            if (num(median) >= target) hi = median;
            else lo = median + 1;
        }
        return lo < n && num(lo) == target? 1 : 0;
    }
};
