#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool isSameAfterReversals(int num) {
        int bum = num;  // store original number
        int rev1 = 0;

        // First reverse
        while(num != 0){
            int k = num % 10;
            rev1 = rev1 * 10 + k;
            num = num / 10;
        }

        // Second reverse
        int rev2 = 0;
        while(rev1 != 0){
            int k = rev1 % 10;
            rev2 = rev2 * 10 + k;
            rev1 = rev1 / 10;
        }

        // Compare original and twice reversed number
        return bum == rev2;
    }
};

int main() {
    Solution sol;
    int num;

    cout << "Enter a number: ";
    cin >> num;

    bool result = sol.isSameAfterReversals(num);
    cout << (result ? "true" : "false") << endl;

    return 0;
}
