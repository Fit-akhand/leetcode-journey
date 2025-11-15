#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool isChar(char ch) {
        if (ch >= 'A' && ch <= 'Z') return true;
        if (ch >= 'a' && ch <= 'z') return true;
        return false;
    }

    string reverseOnlyLetters(string s) {
        int f = 0;
        int e = s.size() - 1;

        while (f < e) {

            if (!isChar(s[f])) {
                f++;
            }
            else if (!isChar(s[e])) {
                e--;
            }
            else {
                swap(s[f], s[e]);
                f++;
                e--;
            }
        }
        return s;
    }
};

int main() {
    Solution sol;
    cout << sol.reverseOnlyLetters("a-bC-dEf-ghIj");
}
