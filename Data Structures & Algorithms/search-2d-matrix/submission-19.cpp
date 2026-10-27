class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        const int row = static_cast<int>(matrix.size());
        const int col = static_cast<int>(matrix[0].size());
        auto num = [&] (int x) {return matrix[x/col][x % col];};
        int lo = 0;
        int n = row * col;
        int hi = n;

        while (lo < hi) {
            int mid = lo + (hi - lo)/2;
            if (num(mid) >= target) {hi = mid;}
            else {lo = mid + 1;}
        }
        return (lo < n) && num(lo) == target;
    }
};
