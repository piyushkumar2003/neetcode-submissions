class Solution {
public:
// Intuition

// Use a hash array of size 9 to check whether any number `1–9` appears more than once in a row, column, or 3×3 box.

// Algorithm

// 1. Traverse each row → count numbers using hash → duplicate ⇒ `false`.
// 2. Traverse each column → same check.
// 3. Traverse all 3×3 boxes → same check.
// 4. If no duplicates found → `true`.

// Key idea: `hash[val] > 0` means the number has appeared more than once.

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
