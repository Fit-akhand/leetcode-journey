#include <bits/stdc++.h>
using namespace std;

class Solution {
public:

    int solveByTabtoSo(string text1, string text2){
        int a = text1.length();
        int b = text2.length();

        vector<int> curr(b + 1, 0);
        vector<int> next(b + 1, 0);

        for(int i = a - 1; i >= 0; i--){
            for(int j = b - 1; j >= 0; j--){
                if(text1[i] == text2[j]){
                    curr[j] = 1 + next[j + 1];
                }
                else{
                    curr[j] = max(curr[j + 1], next[j]);
                }
            }
            next = curr;
        }
        return next[0];
    }

    int longestPalindromeSubseq(string s) {
        string first = s;
        reverse(s.begin(), s.end());
        string second = s;

        return solveByTabtoSo(first, second);
    }
};

int main() {
    string s;
    cout << "Enter string: ";
    cin >> s;

    Solution obj;
    cout << "Longest Palindromic Subsequence length: "
         << obj.longestPalindromeSubseq(s) << endl;

    return 0;
}