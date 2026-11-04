class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        const int rows = matrix.size();
        const int cols = matrix[0].size();
        const auto& num = [&] (const int x) {return matrix[x/cols][x % cols];};
        int lo = 0, n = rows * cols, hi = n;
        while (lo < hi) {
            int med = lo + (hi - lo)/2;
            if (num(med) >= target) hi = med;
            else lo = med + 1;
        }
        return lo < n && num(lo) == target? true : false;
    }
};
