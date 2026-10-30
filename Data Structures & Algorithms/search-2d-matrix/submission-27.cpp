class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int rows = matrix.size();
        int cols = matrix[0].size();
        auto matrix_num = [&] (const int x) {return matrix[x/cols][x % cols];};
        int lo = 0, n = rows * cols, hi = n;
        while (lo < hi) {
            int mid = lo + (hi - lo)/2;
            if (matrix_num(mid) >= target) hi = mid;
            else lo = mid + 1;
        } return lo < n && matrix_num(lo) == target? true : false;
    }
};
