 #include <bits/stdc++.h>
using namespace std;

class Solution {
public:

    int SolveUsingRec(string &a,string& b,int i,int j){
        if(i == a.length()) return b.length()-j;
        if(j == b.length()) return a.length()-i;

        if(a[i] == b[j]){
            return SolveUsingRec(a,b,i+1,j+1);
        }
        else{
            int insert = 1 + SolveUsingRec(a,b,i,j+1);
            int del = 1 + SolveUsingRec(a,b,i+1,j);
            int replace = 1 + SolveUsingRec(a,b,i+1,j+1);
            return min(insert, min(del, replace));
        }
    }

    int SolveByMem(string &a,string& b,int i,int j,vector<vector<int>>&dp){
        if(i == a.length()) return b.length()-j;
        if(j == b.length()) return a.length()-i;

        if(dp[i][j] != -1) return dp[i][j];

        if(a[i] == b[j]){
            return dp[i][j] = SolveByMem(a,b,i+1,j+1,dp);
        }
        else{
            int insert = 1 + SolveByMem(a,b,i,j+1,dp);
            int del = 1 + SolveByMem(a,b,i+1,j,dp);
            int replace = 1 + SolveByMem(a,b,i+1,j+1,dp);
            return dp[i][j] = min(insert, min(del, replace));
        }
    }

    int SolveByTab(string&a, string&b){
        int n = a.length();
        int m = b.length();

        vector<vector<int>> dp(n+1, vector<int>(m+1, 0));

        for(int j=0;j<=m;j++) dp[n][j] = m-j;
        for(int i=0;i<=n;i++) dp[i][m] = n-i;

        for(int i=n-1;i>=0;i--){
            for(int j=m-1;j>=0;j--){
                if(a[i] == b[j]){
                    dp[i][j] = dp[i+1][j+1];
                }
                else{
                    int insert = 1 + dp[i][j+1];
                    int del = 1 + dp[i+1][j];
                    int replace = 1 + dp[i+1][j+1];
                    dp[i][j] = min(insert, min(del, replace));
                }
            }
        }
        return dp[0][0];
    }

    int SolveByTabSo(string&a, string&b){
        int n = a.length();
        int m = b.length();

        vector<int> curr(m+1, 0);   // FIXED
        vector<int> next(m+1, 0);

        for(int j=0;j<=m;j++){
            next[j] = m-j;
        }

        for(int i=n-1;i>=0;i--){
            curr[m] = n-i;

            for(int j=m-1;j>=0;j--){
                if(a[i] == b[j]){
                    curr[j] = next[j+1];
                }
                else{
                    int insert = 1 + curr[j+1];
                    int del = 1 + next[j];
                    int replace = 1 + next[j+1];
                    curr[j] = min(insert, min(del, replace));
                }
            }
            next = curr;
        }
        return next[0];
    }

    int minDistance(string word1, string word2) {
        int n = word1.length();
        int m = word2.length();

        if(n == 0) return m;
        if(m == 0) return n;

        // vector<vector<int>> dp(n, vector<int>(m, -1));
        // return SolveByMem(word1,word2,0,0,dp);

        return SolveByTabSo(word1,word2);
    }
};

int main() {
    string s1, s2;

    cout << "Enter first string: ";
    cin >> s1;

    cout << "Enter second string: ";
    cin >> s2;

    Solution obj;
    cout << "Minimum Edit Distance: "
         << obj.minDistance(s1, s2) << endl;

    return 0;
}