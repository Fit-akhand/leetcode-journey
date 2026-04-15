#include <bits/stdc++.h>
using namespace std;

class Solution {
public:

    int solveUsingRecursion(string text1, string text2, int i, int j){
        if(i == text1.length() || j == text2.length()){
            return 0;
        }

        if(text1[i] == text2[j]){
            return 1 + solveUsingRecursion(text1, text2, i+1, j+1);
        }
        else{
            return max(
                solveUsingRecursion(text1, text2, i, j+1),
                solveUsingRecursion(text1, text2, i+1, j)
            );
        }
    }

    int solveUsingMem(string &text1, string &text2, int i, int j, vector<vector<int>>& dp){
        if(i == text1.length() || j == text2.length()){
            return 0;
        }

        if(dp[i][j] != -1){
            return dp[i][j];
        }

        if(text1[i] == text2[j]){
            return dp[i][j] = 1 + solveUsingMem(text1, text2, i+1, j+1, dp);
        }
        else{
            return dp[i][j] = max(
                solveUsingMem(text1, text2, i, j+1, dp),
                solveUsingMem(text1, text2, i+1, j, dp)
            );
        }
    }

    int solveByTab(string text1, string text2){
        int a = text1.length();
        int b = text2.length();

        vector<vector<int>> dp(a+1, vector<int>(b+1, 0));

        for(int i = a-1; i >= 0; i--){
            for(int j = b-1; j >= 0; j--){
                if(text1[i] == text2[j]){
                    dp[i][j] = 1 + dp[i+1][j+1];
                }
                else{
                    dp[i][j] = max(dp[i][j+1], dp[i+1][j]);
                }
            }
        }
        return dp[0][0];
    }

    int longestCommonSubsequence(string text1, string text2) {

        // return solveUsingRecursion(text1, text2, 0, 0);

        // vector<vector<int>> dp(text1.length(), vector<int>(text2.length(), -1));
        // return solveUsingMem(text1, text2, 0, 0, dp);

        return solveByTab(text1, text2);
    }
};

int main() {
    string text1, text2;

    cout << "Enter first string: ";
    cin >> text1;

    cout << "Enter second string: ";
    cin >> text2;

    Solution obj;
    cout << "LCS length: " << obj.longestCommonSubsequence(text1, text2) << endl;

    return 0;
}