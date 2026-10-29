class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        int bit_rows[9] = {0}, bit_cols[9] = {0}, bit_boxes[3][3] = {0};
        for (int r = 0; r < board.size(); ++r) {
            for (int c = 0; c < board[0].size(); ++c) {
                char ch = board[r][c];
                if (ch == '.') continue;
                int bit_index = ch - '1';
                int bit_mask = 1 << bit_index;
                if ((bit_rows[r] | bit_cols[c] |
                        bit_boxes[r/3][c/3]) & bit_mask) return false;
                else {  bit_rows[r] |= bit_mask;
                        bit_cols[c] |= bit_mask;
                        bit_boxes[r/3][c/3] |= bit_mask; }
            }
        } return true;
    }
};
