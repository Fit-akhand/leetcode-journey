#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maximumWealth(vector<vector<int>>& accounts) {
        int mx = -1;
        
        for(int i = 0; i < accounts.size(); i++){
            int sum = 0;

            for(int j = 0; j < accounts[i].size(); j++){
                sum += accounts[i][j];
            }

            if(sum > mx){
                mx = sum;
            }
        }

        return mx;
    }
};

int main() {
    Solution s;

    vector<vector<int>> accounts = {
        {1, 2, 3},
        {3, 2, 1},
        {4, 1, 2}
    };

    cout << s.maximumWealth(accounts) << endl;  // Output: 7

    return 0;
}
