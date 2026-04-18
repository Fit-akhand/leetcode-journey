#include <bits/stdc++.h>
using namespace std;

class Solution {
public:

    int solveUsingRecursion(vector<int>& days, vector<int>& costs,int i){
        if(i >= days.size()) return 0;

        int cost1 = costs[0] + solveUsingRecursion(days,costs,i+1);

        int j = i;
        int end_day = days[i] + 6;
        while(j < days.size() && days[j] <= end_day) j++;
        int cost7 = costs[1] + solveUsingRecursion(days,costs,j);

        int k = i;
        int last_day = days[i] + 29;
        while(k < days.size() && days[k] <= last_day) k++;
        int cost30 = costs[2] + solveUsingRecursion(days,costs,k);

        return min({cost1, cost7, cost30});
    }

    int solveUsingMem(vector<int>& days, vector<int>& costs,int i,vector<int>&dp){
        if(i >= days.size()) return 0;

        if(dp[i] != -1) return dp[i];

        int cost1 = costs[0] + solveUsingMem(days,costs,i+1,dp);

        int j = i;
        int end_day = days[i] + 6;
        while(j < days.size() && days[j] <= end_day) j++;
        int cost7 = costs[1] + solveUsingMem(days,costs,j,dp);

        int k = i;
        int last_day = days[i] + 29;
        while(k < days.size() && days[k] <= last_day) k++;
        int cost30 = costs[2] + solveUsingMem(days,costs,k,dp);

        return dp[i] = min({cost1, cost7, cost30});
    }
    
    int solveUsingTab(vector<int>& days, vector<int>& costs){
        int n = days.size();
        vector<int> dp(n+1,0);

        for(int i = n-1; i >= 0; i--){
            int cost1 = costs[0] + dp[i+1];

            int j = i;
            int end_day = days[i] + 6;
            while(j < n && days[j] <= end_day) j++;
            int cost7 = costs[1] + dp[j];

            int k = i;
            int last_day = days[i] + 29;
            while(k < n && days[k] <= last_day) k++;
            int cost30 = costs[2] + dp[k];

            dp[i] = min({cost1, cost7, cost30});
        }
        return dp[0];
    }

    int mincostTickets(vector<int>& days, vector<int>& costs) {
        // return solveUsingRecursion(days,costs,0);

        // vector<int> dp(days.size(), -1);
        // return solveUsingMem(days,costs,0,dp);

        return solveUsingTab(days,costs);
    }
};

int main() {
    int n;
    cout << "Enter number of travel days: ";
    cin >> n;

    vector<int> days(n);
    cout << "Enter days: ";
    for(int i = 0; i < n; i++) cin >> days[i];

    vector<int> costs(3);
    cout << "Enter costs for 1-day, 7-day, 30-day passes: ";
    for(int i = 0; i < 3; i++) cin >> costs[i];

    Solution obj;
    cout << "Minimum Cost: " << obj.mincostTickets(days, costs) << endl;

    return 0;
}