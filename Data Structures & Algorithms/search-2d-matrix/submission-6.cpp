class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int m = static_cast<int>(matrix.size());
        int n;
        if (!matrix.empty()) { n = static_cast<int>(matrix[0].size());}
        else return false;
        
        int left = 0;
        int right = m * n - 1;

        while (left <= right) {
            int median = left + (right - left)/2;

            if(target < matrix[median / n][median % n]) {
                right = median -1 ;
            } else if (target > matrix[median / n][median % n]) {
                left = median + 1;
            } else {
                return true;
            }
        }
        return false;
    }
};