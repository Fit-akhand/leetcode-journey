#include <iostream>
#include <vector>
#include <string>
using namespace std;

class Solution {
public:

    bool isSafe(int row,int col,vector<vector<char>>& board,int n){
        // check row on left
        for(int i = col-1; i >= 0; i--){
            if(board[row][i] == 'Q'){
                return false;
            }
        }

        // check upper-left diagonal
        int i = row-1, j = col-1;
        while(i >= 0 && j >= 0){
            if(board[i][j] == 'Q'){
                return false;
            }
            i--;
            j--;
        }

        // check lower-left diagonal
        int x = row+1, y = col-1;
        while(x < n && y >= 0){
            if(board[x][y] == 'Q'){
                return false;
            }
            x++;
            y--;
        }

        return true;
    }

    void storeSol(vector<vector<char>>& board,vector<vector<string>>& ans,int n){
        vector<string> temp;
        for(int i=0; i<n; i++){
            string rowStr = "";
            for(int j=0; j<n; j++){
                rowStr.push_back(board[i][j]);
            }
            temp.push_back(rowStr);
        }
        ans.push_back(temp);
    }

    void solve(vector<vector<char>>& board,vector<vector<string>>& ans,int n,int col){
        if(col >= n){
            storeSol(board,ans,n);
            return;
        }

        for(int row=0; row<n; row++){
            if(isSafe(row,col,board,n)){
                board[row][col] = 'Q';      // place queen
                solve(board,ans,n,col+1);   // move to next column
                board[row][col] = '.';      // backtrack
            }
        }
    }

    vector<vector<string>> solveNQueens(int n) {
        vector<vector<string>> ans;
        vector<vector<char>> board(n, vector<char>(n,'.'));
        solve(board,ans,n,0);
        return ans;
    }
};

int main() {
    Solution s;
    int n;
    cout << "Enter N for N-Queens: ";
    cin >> n;

    vector<vector<string>> result = s.solveNQueens(n);

    cout << "Total solutions: " << result.size() << endl;
    for(auto& sol : result){
        cout << "-----" << endl;
        for(auto& row : sol){
            cout << row << endl;
        }
    }
    return 0;
}
