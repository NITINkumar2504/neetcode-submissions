class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        unordered_set<string> s;

        for(int i = 0; i < 9; i++){
            for(int j = 0; j < 9; j++){

                if(board[i][j] == '.') continue;

                int val = board[i][j];
                string row = to_string(val) + "_row_" + to_string(i);
                string col = to_string(val) + "_col_" + to_string(j);
                string box = to_string(val) + "_box_" + to_string(i / 3) + '_' + to_string(j / 3);

                if(s.count(row) || s.count(col) || s.count(box)) return false;
                
                s.insert(row);
                s.insert(col);
                s.insert(box);
            }
        }

        return true;
    }
};