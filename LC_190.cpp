#include <iostream>
using namespace std;

class Solution {
public:
    int reverseBits(int n) {
        unsigned int result = 0;

        for (int i = 0; i < 32; i++) {
            result <<= 1;
            result |= (n & 1);
            n >>= 1;
        }

        return result;
    }
};

int main() {
    Solution sol;

    int n;
    cout << "Enter an integer: ";
    cin >> n;

    int reversed = sol.reverseBits(n);

    cout << "Reversed bits result: " << reversed << endl;

    return 0;
}
