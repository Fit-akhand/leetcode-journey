#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    string addStrings(string a, string b) {
        int i = a.size() - 1;
        int j = b.size() - 1;
        int carry = 0;
        string res;

        while (i >= 0 || j >= 0 || carry) {
            int sum = carry;
            if (i >= 0) sum += a[i--] - '0';
            if (j >= 0) sum += b[j--] - '0';

            res.push_back((sum % 10) + '0');
            carry = sum / 10;
        }

        reverse(res.begin(), res.end());
        return res;
    }
};

int main() {
    Solution sol;
    string num1, num2;

    cout << "Enter first number: ";
    cin >> num1;
    cout << "Enter second number: ";
    cin >> num2;

    string result = sol.addStrings(num1, num2);
    cout << "Sum = " << result << endl;

    return 0;
}
