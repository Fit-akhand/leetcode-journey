#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int countOdds(int low, int high) {
        return (high + 1) / 2 - (low / 2);
    }
};

int main() {
    int low, high;
    cout << "Enter low and high: ";
    cin >> low >> high;

    Solution sol;
    int result = sol.countOdds(low, high);

    cout << "Number of odd numbers in range: " << result << endl;

    return 0;
}
