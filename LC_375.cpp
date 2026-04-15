#include <bits/stdc++.h>
using namespace std;

class Solution {
public:

    int solveUsingRecursion(int start,int end){
        if(start >= end){
            return 0;
        }
        int ans = INT_MAX;
        for(int i=start;i<=end;i++){
            ans = min(ans, i + max(solveUsingRecursion(start,i-1),
                                  solveUsingRecursion(i+1,end)));
        }
        return ans;
    }

    int solveUsingMem(int start,int end,vector<vector<int>>&dp){
        if(start >= end){
            return 0;
        }
        if(dp[start][end]!=-1){
            return dp[start][end];
        }
        int ans = INT_MAX;
        for(int i=start;i<=end;i++){
            ans = min(ans, i + max(solveUsingMem(start,i-1,dp),
                                  solveUsingMem(i+1,end,dp)));
        }
        dp[start][end] = ans;
        return ans;
    }

    int SolveUsingTab(int n){
        vector<vector<int>> dp(n+2, vector<int>(n+2, 0));

        for(int s = n; s >= 1; s--){
            for(int e = s+1; e <= n; e++){   // optimized loop
                int ans = INT_MAX;
                for(int i = s; i <= e; i++){
                    ans = min(ans, i + max(dp[s][i-1], dp[i+1][e]));
                }
                dp[s][e] = ans;
            }
        }
        return dp[1][n];
    }

    int getMoneyAmount(int n) {
        // Uncomment any version you want:
        
        // return solveUsingRecursion(1,n);

        // vector<vector<int>> dp(n+1,vector<int>(n+1,-1));
        // return solveUsingMem(1,n,dp);

        return SolveUsingTab(n);
    }
};

int main() {
    int n;
    cout << "Enter n: ";
    cin >> n;

    Solution obj;
    cout << "Minimum money required: " << obj.getMoneyAmount(n) << endl;

    return 0;
}