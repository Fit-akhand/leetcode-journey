#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int longestValidParentheses(string s) {
        stack<int> st;
        st.push(-1);  // Base index for valid substring calculation
        int maxlen = 0;

        for (int i = 0; i < s.size(); i++) {
            if (s[i] == '(') {
                st.push(i);
            } else {
                st.pop();
                if (st.empty()) {
                    st.push(i);
                } else {
                    maxlen = max(maxlen, i - st.top());
                }
            }
        }
        return maxlen;
    }
};

int main() {
    Solution sol;
    string s;

    cout << "Enter parentheses string: ";
    cin >> s;

    cout << "Longest valid parentheses length: "
         << sol.longestValidParentheses(s) << endl;

    return 0;
}
