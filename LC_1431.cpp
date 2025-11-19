#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<bool> kidsWithCandies(vector<int>& candies, int extraCandies) {
        vector<bool> ans;
        int mx = -1;

        // Find maximum candies any kid currently has
        for(int c : candies){
            if(c > mx){
                mx = c;
            }
        }

        // Check for each kid
        for(int c : candies){
            if(c + extraCandies >= mx){
                ans.push_back(true);
            } else {
                ans.push_back(false);
            }
        }

        return ans;
    }
};

int main() {
    Solution s;
    vector<int> candies = {2, 3, 5, 1, 3};
    int extraCandies = 3;

    vector<bool> result = s.kidsWithCandies(candies, extraCandies);

    for(bool x : result){
        cout << (x ? "true" : "false") << " ";
    }
    cout << endl;

    return 0;
}
