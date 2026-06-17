class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        vector<unordered_set<char>> columns(9);
        vector<unordered_set<char>> rows(9);
        vector<unordered_set<char>> sub_boxes(9);
        
        int column_size = 9;
        int row_size = 9;   

        for (int c = 0; c < column_size; c++) {
            for (int r = 0; r < row_size; r++) {
                
                // check rows for duplicates
                if (board[r][c] != '.') {
                auto [row_it, row_inserted] = rows[c].insert(board[r][c]);
                if (!row_inserted) {return false;}
                }

                // check columnss for duplicates                
                if (board[c][r] != '.') {
                auto [col_it, col_inserted] = columns[c].insert(board[c][r]);
                if (!col_inserted) {return false;}
                }

                // check boxes for duplicates    
                if (board[r][c] == '.') {continue;}
                auto [it, inserted] = sub_boxes[(r/3)*3 + c/3].insert(board[r][c]);
                if (!inserted) {return false;}
            }
        }
        return true;
    }
};
