#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int titleToNumber(string columnTitle) {
        reverse(columnTitle.begin(), columnTitle.end());
        long long ans = 0;
        long long p = 1;

        for(char c : columnTitle){
            int x = c - 'A' + 1;   // Convert A→1, B→2, ..., Z→26
            ans += x * p;          // Add contribution
            p *= 26;               // Increase base power
        }

        return ans;
    }
};

int main() {
    Solution s;

    // 🔹 Test cases (you can change input)
    cout << s.titleToNumber("A") << endl;    // 1
    cout << s.titleToNumber("AB") << endl;   // 28
    cout << s.titleToNumber("ZY") << endl;   // 701
    cout << s.titleToNumber("FXSHRXW") << endl; // 2147483647

    return 0;
}
