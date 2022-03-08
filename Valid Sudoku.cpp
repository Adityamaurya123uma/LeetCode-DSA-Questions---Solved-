class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        
    vector<set<char>> row(9), col(9), block(9);
        
        for(int i = 0; i < 9; i++) {
            for(int j = 0; j < 9; j++) {
                if(board[i][j] != '.') {
                    char c = board[i][j];
                    if(!row[j].insert(c).second or !col[i].insert(c).second or !block[(i/3)*3 + j/3].insert(c).second) 
						return false;
               }
            }
        }
        return true;
        
    }
};