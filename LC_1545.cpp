#include <iostream>
using namespace std;

class Solution {
public:
    char findKthBit(int n, int k) {
        // Base case
        if (n == 1) 
            return '0';

        int length = (1 << n) - 1;   // 2^n - 1
        int mid = length / 2 + 1;    // middle position

        // If k is middle
        if (k == mid) 
            return '1';

        // If k is in left half
        if (k < mid) 
            return findKthBit(n - 1, k);

        // If k is in right half
        int mirrored = length - k + 1;
        char bit = findKthBit(n - 1, mirrored);

        // Invert the bit
        return (bit == '0') ? '1' : '0';
    }
};

int main() {
    Solution sol;
    cout << sol.findKthBit(3, 1) << endl;  // Example test
    return 0;
}