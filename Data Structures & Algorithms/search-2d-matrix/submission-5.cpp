class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int m = static_cast<int>(matrix.size());
        int n;
        if (!matrix.empty()) { n = static_cast<int>(matrix[0].size());}
        else return false;
        
        int top = 0;
        int bottom = m - 1;

        while (top <= bottom) {
            int col_median = top + (bottom - top)/2;
            int first = matrix[col_median][0];
            int last = matrix[col_median][n - 1];

            if (target > last) {
                top = col_median + 1;
            } else if(target < first) {
                bottom = col_median - 1;
            } else { // target >= first && target <= last
                int left = 0;
                int right = n - 1;
            
                while (left <= right) {
                    int row_median = left + (right - left)/2;
                    int median = matrix[col_median][row_median];
                    
                    if (target < median) {
                        right = row_median - 1;
                    } else if(target > median) {
                        left = row_median + 1;
                    } else {return true;}
                }
                return false;
            }
        }
        return false;
    }
};