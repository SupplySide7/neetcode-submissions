class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        const int rows = static_cast<int>(matrix.size());
        const int cols = static_cast<int>(matrix[0].size());
        auto num = [&] (int i) {return matrix[i/cols][i % cols];};
        int lo = 0;
        int hi = rows * cols;

        while (lo < hi) {
            int mid = lo + (hi - lo)/2;
            if (num(mid) >= target) {hi = mid;} // mid is true: answer is mid or left of it
            else {lo = mid + 1;} // mid is false: mid and everything left of it is false
        }
        // check for all values being < target, and target exisitng in matrix
        return lo < (rows * cols) && num(lo) == target;
    }
};
