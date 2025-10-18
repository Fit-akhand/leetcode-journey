#include <iostream>
#include <stack>
#include <string>
using namespace std;

class Solution {
public:
    bool isValid(string s) {
        stack<char> st;
        for (char ch : s) {
            if (ch == 'c') {
                if (st.size() >= 2) {
                    char b = st.top(); st.pop();
                    char a = st.top(); st.pop();
                    if (a != 'a' || b != 'b') return false;
                } else {
                    return false;
                }
            } else {
                st.push(ch);  // push 'a' or 'b'
            }
        }
        return st.empty();
    }
};

int main() {
    Solution sol;
    string s;
    cout << "Enter a string: ";
    cin >> s;

    if (sol.isValid(s)) {
        cout << "Valid string ✅" << endl;
    } else {
        cout << "Invalid string ❌" << endl;
    }

    return 0;
}
