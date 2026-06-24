class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int m = static_cast<int>(matrix.size());
        int n;
        if (!matrix.empty()) { n = static_cast<int>(matrix[0].size());}
        else return false;
        int left = 0;
        int right = n - 1;

        for (int i = 0; i < m; i++) {

            if (target >= matrix[i][left] && target <= matrix[i][right]) {
                
                while (left <= right) {
                    int median = left + (right - left)/2;

                    if (target < matrix[i][median]) {
                        right = median - 1;

                    } else if(target > matrix[i][median]) {
                        left = median + 1;
                    } else {return true;}
                }
            }
        }
        return false;
    }
};
