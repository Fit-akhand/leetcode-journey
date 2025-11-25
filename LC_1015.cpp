#include <iostream>
using namespace std;

class Solution {
public:
    int smallestRepunitDivByK(int k) {
        // If k has factor 2 or 5, no number of 1's will be divisible by k
        if (k % 2 == 0 || k % 5 == 0) {
            return -1;
        }

        int remainder = 0;
        for (int count = 1; count <= k; count++) {
            remainder = (remainder * 10 + 1) % k;
            if (remainder == 0) {
                return count;
            }
        }

        return -1; // Safe fallback
    }
};

int main() {
    Solution sol;
    int k;

    cout << "Enter value of k: ";
    cin >> k;

    int result = sol.smallestRepunitDivByK(k);

    if (result == -1) {
        cout << "No repunit divisible by " << k << endl;
    } else {
        cout << "Smallest repunit divisible by " << k << " has length: " << result << endl;
    }

    return 0;
}
