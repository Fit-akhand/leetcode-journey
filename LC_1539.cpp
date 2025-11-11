#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int findKthPositive(vector<int>& arr, int k) {
        int i = 0;
        int curr = 1;
        int n = arr.size();

        while (k > 0) {
            if (i < n && arr[i] == curr) {
                i++;  // skip number present in arr
            } else {
                k--;  // found a missing number
                if (k == 0) return curr;  // kth missing found
            }
            curr++;
        }

        return curr - 1;
    }
};

int main() {
    Solution sol;

    // Example test case
    vector<int> arr = {2, 3, 4, 7, 11};
    int k = 5;

    cout << "Input arr: [2, 3, 4, 7, 11]" << endl;
    cout << "k = " << k << endl;

    int result = sol.findKthPositive(arr, k);

    cout << "Kth missing positive number = " << result << endl;

    return 0;
}
