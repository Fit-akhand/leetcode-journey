#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<vector<int>> minimumAbsDifference(vector<int>& arr) {
        vector<vector<int>> brr;
        sort(arr.begin(), arr.end());

        int n = arr.size();
        int minDiff = INT_MAX;

        // Find minimum adjacent difference
        for (int i = 0; i < n - 1; i++) {
            minDiff = min(minDiff, arr[i + 1] - arr[i]);
        }

        // Collect pairs with minimum difference
        for (int i = 0; i < n - 1; i++) {
            if (arr[i + 1] - arr[i] == minDiff) {
                brr.push_back({arr[i], arr[i + 1]});
            }
        }

        return brr;
    }
};

int main() {
    vector<int> arr = {4, 2, 1, 3};

    Solution sol;
    vector<vector<int>> result = sol.minimumAbsDifference(arr);

    cout << "Pairs with minimum absolute difference:\n";
    for (auto &v : result) {
        cout << v[0] << " " << v[1] << endl;
    }

    return 0;
}
