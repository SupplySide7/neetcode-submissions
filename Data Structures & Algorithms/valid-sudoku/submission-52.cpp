class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        const int SIZE = static_cast<int>(board.size());
        const int BOX_SIZE = SIZE/3;
        vector<int> row_bits(SIZE, 0);
        vector<int> col_bits(SIZE, 0);
        vector<vector<int>> box_bits(BOX_SIZE, vector<int>(BOX_SIZE));
        //int row_bits[SIZE] = {0};
        //int col_bits[SIZE] = {0};
        //int box_bits[BOX_SIZE][BOX_SIZE] = {0};
        
        for (int r = 0; r < SIZE; ++r) {
            for (int c = 0; c < SIZE; ++c) {
                const char ch = board[r][c];
                if (ch == '.') continue;
                int bitmask = ch - '1';
                if ((row_bits[r] | col_bits[c] | 
                        box_bits[r/BOX_SIZE][c/BOX_SIZE]) & 1 << bitmask) return false;
                row_bits[r] |= 1 << bitmask;
                col_bits[c] |= 1 << bitmask;
                box_bits[r/BOX_SIZE][c/BOX_SIZE] |= 1 << bitmask;
            }
        } return true;
    }
};
