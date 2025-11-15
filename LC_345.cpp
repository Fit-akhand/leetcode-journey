#include <bits/stdc++.h>
using namespace std;

class Solution {
public:

    bool isvowel(char ch){
        return (
            ch=='a' || ch=='e' || ch=='i' || ch=='o' || ch=='u' ||
            ch=='A' || ch=='E' || ch=='I' || ch=='O' || ch=='U'
        );
    }

    string reverseVowels(string s) {

        int f = 0, e = s.size() - 1;

        while (f < e) {

            if (!isvowel(s[f])) {
                f++;
            }
            else if (!isvowel(s[e])) {
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
    cout << sol.reverseVowels("hello");  // Output: holle
}
