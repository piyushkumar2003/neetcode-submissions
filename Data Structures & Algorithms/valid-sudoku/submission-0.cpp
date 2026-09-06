class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        // for rows
        for(int i = 0; i<9; i++){
            vector<int>hash(9,-1);
            for(int j = 0; j<9; j++){
                if(board[i][j] == '.') continue;
                int val = board[i][j]-'1';
                hash[val]++;
            }

            for(int k = 0; k<9; k++){
                if(hash[k] > 0) return false;
            }
        }
        // for cols
        for(int i = 0; i<9; i++){
            vector<int>hash(9,-1);
            for(int j = 0; j<9; j++){
                if(board[j][i] == '.') continue;
                int val = board[j][i]-'1';
                hash[val]++;
            }

            for(int k = 0; k<9; k++){
                if(hash[k] > 0) return false;
            }
        }
        // for 3x3 sqs
        for(int I = 0; I<9; I = I+3){
            for(int J = 0; J<9; J = J+3){
                vector<int>hash(9,-1);
                for(int i = 0; i<3; i++){
                    for(int j = 0; j<3; j++){
                        if(board[i+I][j+J] == '.') continue;
                        int val = board[i+I][j+J]-'1';
                        hash[val]++;
                    }

                }
                for(int k = 0; k<9; k++){
                    if(hash[k] > 0) return false;
                }
            }
        }
        return true;
    }
};
