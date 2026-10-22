class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        const int DIM = 9;
        const int BUCKET = 3;
        vector<int> rows(DIM, 0);
        vector<int> cols(DIM, 0);
        vector<vector<int>> boxes(BUCKET, vector<int>(BUCKET, 0));

        for (int r = 0; r < DIM; r++) {
            for (int c = 0; c < DIM; c++) {
                const char digit = board[r][c];
                if (digit == '.') {continue;}
                int index = digit - '1'; // 0 based indexing from 0 to 8.
                int bit_mask = 1 << index;
                int br = r/3;
                int bc = c/3;
                if ((rows[r] | cols[c] | boxes[br][bc]) & bit_mask) {
                    return false;
                }
                rows[r] |= bit_mask;
                cols[c] |= bit_mask;
                boxes[br][bc] |= bit_mask;
            }
        }
        return true;
    }
};
