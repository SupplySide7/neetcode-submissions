class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        vector<unordered_set<char>> columns(9);
        vector<unordered_set<char>> rows(9);
        vector<unordered_set<char>> sub_boxes(9);
        
        int column_size = 9;
        int row_size = 9;   

        for (int i = 0; i < column_size; i++) {
            for (int j = 0; j < row_size; j++) {
                
                if (board[i][j] != '.') {
                auto [row_it, row_inserted] = rows[i].insert(board[i][j]);
                if (!row_inserted) {return false;}
                }

                if (board[j][i] != '.') {
                auto [col_it, col_inserted] = columns[i].insert(board[j][i]);
                if (!col_inserted) {return false;}
                }

                if (board[i][j] == '.') {continue;}
                auto [it, inserted] = sub_boxes[(j/3)*3 + i/3].insert(board[i][j]);
                if (!inserted) {return false;}
            }
        }
        return true;
    }
};
