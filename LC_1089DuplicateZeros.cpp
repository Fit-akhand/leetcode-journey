#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    void duplicateZeros(vector<int>& arr) {
        int n = arr.size();
        int zeros = 0;

        // Step 1: Count zeros
        for (int num : arr) {
            if (num == 0) zeros++;
        }

        // Step 2: Traverse backward
        for (int i = n - 1; i >= 0; i--) {
            int newPos = i + zeros; // shifted index

            // Copy element if within bounds
            if (newPos < n) {
                arr[newPos] = arr[i];
            }

            // Duplicate zero if needed
            if (arr[i] == 0) {
                zeros--;
                if (i + zeros < n) {
                    arr[i + zeros] = 0;
                }
            }
        }
    }
};

int main() {
    Solution sol;

    // Example input
    vector<int> arr = {1, 0, 2, 3, 0, 4, 5, 0};

    cout << "Original array: ";
    for (int x : arr) cout << x << " ";
    cout << endl;

    // Function call
    sol.duplicateZeros(arr);

    cout << "After duplicating zeros: ";
    for (int x : arr) cout << x << " ";
    cout << endl;

    return 0;
}
