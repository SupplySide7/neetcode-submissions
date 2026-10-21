class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        int rows[9] = {0};
        int cols[9] = {0};
        int boxes[9] = {0};

        for (int r = 0; r < 9; r++) {
            for (int c = 0; c < 9; c++) {
                const char ch = board[r][c];
                if (ch == '.') {continue;}
                int index = ch - '1';
                int bit_mask = (1 << index);
                int box_index = (r/3) * 3 + (c/3);
                if ((rows[r] | cols[c] | boxes[box_index]) & bit_mask) {
                    return false;
                }
                rows[r] |= bit_mask;
                cols[c] |= bit_mask;
                boxes[box_index] |= bit_mask;
            }
        }
        return true;
    }
};
