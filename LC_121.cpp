#include <bits/stdc++.h>
using namespace std;

class Solution {
public:

    void maxProfitFinder(vector<int>& prices, int i, int& minPrice, int& maxProfit) {
        // base case
        if(i == prices.size()) return;

        if(prices[i] < minPrice) minPrice = prices[i];

        int todayProfit = prices[i] - minPrice;
        if(todayProfit > maxProfit) maxProfit = todayProfit;

        maxProfitFinder(prices, i+1, minPrice, maxProfit);
    }

    int maxProfit(vector<int>& prices) {
        int minPrice = INT_MAX;
        int maxProfit = 0;   // fixed

        maxProfitFinder(prices, 0, minPrice, maxProfit);
        return maxProfit;
    }
};

int main() {
    Solution obj;
    vector<int> prices = {7,1,5,3,6,4};

    cout << "Max Profit: " << obj.maxProfit(prices);

    return 0;
}