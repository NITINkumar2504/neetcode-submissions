class Solution {
public:
    bool traverse(vector<vector<char>>& board, int sr, int er, int sc, int ec){
        unordered_set<char> s;
        
        for(int row = sr; row <= er; row++){
            for(int col = sc; col <= ec; col++){
                if(board[row][col] == '.') continue;

                if(s.count(board[row][col])) return false;
                else s.insert(board[row][col]);
            }
        }

        return true;
    }

    bool isValidSudoku(vector<vector<char>>& board) {
        int rows = board.size();
        int cols = board[0].size();

        // check rows
        for(int row = 0; row < rows; row++){
            unordered_set<char> s;

            for(int col = 0; col < cols; col++){
                if(board[row][col] == '.') continue;

                if(s.count(board[row][col])) return false;
                else s.insert(board[row][col]);
            }
        }

        // check cols
        for(int col = 0; col < cols; col++){
            unordered_set<char> s;

            for(int row = 0; row < rows; row++){
                if(board[row][col] == '.') continue;

                if(s.count(board[row][col])) return false;
                else s.insert(board[row][col]);
            }
        }

        // check 3*3 grid
        for(int sr = 0; sr < rows; sr += 3){
            int er = sr + 2;

            for(int sc = 0; sc < cols; sc += 3){
                int ec = sc + 2;

                if(!traverse(board, sr, er, sc, ec)) return false;
            }
        }

        return true;
    }
};