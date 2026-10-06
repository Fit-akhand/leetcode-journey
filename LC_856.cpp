#include <iostream>
#include <stack>
#include <string>
using namespace std;

class Solution {
public:
    int scoreOfParentheses(string s) {
        stack<int> st;
        st.push(0);

        for(int i = 0; i < s.size(); i++) {

            if(s[i] == '(') {
                st.push(0);
            }

            else {
                int innerScore = st.top();
                st.pop();

                int score;

                if(innerScore == 0) {
                    score = 1;
                }
                else {
                    score = 2 * innerScore;
                }

                st.top() = st.top() + score;
            }
        }

        return st.top();
    }
};

int main() {
    Solution obj;

    string s;
    cout << "Enter parentheses: ";
    cin >> s;

    int result = obj.scoreOfParentheses(s);

    cout << "Score = " << result << endl;

    return 0;
}