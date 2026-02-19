#include <iostream>
#include <string>
using namespace std;

class Solution {
public:
    int countBinarySubstrings(string s) {
        int prev = 0;
        int curr = 1;
        int ans = 0;

        for (int i = 1; i < s.length(); i++) {
            if (s[i] == s[i - 1]) {
                curr++;
            } else {
                ans += min(prev, curr);
                prev = curr;
                curr = 1;
            }
        }

        ans += min(prev, curr);
        return ans;
    }
};

int main() {
    Solution obj;

    string s;
    cout << "Enter binary string: ";
    cin >> s;

    int result = obj.countBinarySubstrings(s);

    cout << "Output: " << result << endl;
    return 0;
}
