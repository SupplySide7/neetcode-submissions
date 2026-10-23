class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        const int SIZE = 9;
        const int BUCKET_SIZE = 3;
        int rows[9] = {0};
        int cols[9] = {0};
        int boxes[3][3] = {0};

        for (int r = 0; r < SIZE; r++) {
            for (int c = 0; c < SIZE; c++) {
                const char& ch = board[r][c];
                if (ch == '.') {continue;}
                int bit_index = ch - '1';
                int bit_mask = 1 << bit_index;
                
                if ((rows[r] | cols[c] | boxes[r/BUCKET_SIZE][c/BUCKET_SIZE]) & bit_mask) {
                    return false;
                } else {
                    rows[r] |= bit_mask;
                    cols[c] |= bit_mask;
                    boxes[r/BUCKET_SIZE][c/BUCKET_SIZE] |= bit_mask;
                }
            }
        }
        return true;
    }
};
