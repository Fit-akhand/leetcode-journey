#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    vector<int> replaceElements(vector<int>& arr) {
        int n = arr.size();
        vector<int> ans(n);

        for (int i = 0; i < n - 1; i++) {
            int maxi = -1;
            for (int j = i + 1; j < n; j++) {
                if (arr[j] > maxi) {
                    maxi = arr[j];
                }
            }
            ans[i] = maxi;
        }

        ans[n - 1] = -1;
        return ans;
    }
};

int main() {
    Solution s;
    vector<int> arr = {17, 18, 5, 4, 6, 1};

    vector<int> ans = s.replaceElements(arr);

    for (int x : ans) {
        cout << x << " ";
    }

    return 0;
}
