#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack<int> st;

        for(int i = 0; i < tokens.size(); i++) {

            if(tokens[i] == "+") {
                int a = st.top();
                st.pop();

                int b = st.top();
                st.pop();

                int c = b + a;
                st.push(c);
            }

            else if(tokens[i] == "-") {
                int a = st.top();
                st.pop();

                int b = st.top();
                st.pop();

                int c = b - a;
                st.push(c);
            }

            else if(tokens[i] == "*") {
                int a = st.top();
                st.pop();

                int b = st.top();
                st.pop();

                int c = b * a;
                st.push(c);
            }

            else if(tokens[i] == "/") {
                int a = st.top();
                st.pop();

                int b = st.top();
                st.pop();

                int c = b / a;
                st.push(c);
            }

            else {
                st.push(stoi(tokens[i]));
            }
        }

        return st.top();
    }
};

int main() {

    Solution obj;

    vector<string> tokens = {
        "2", "1", "+", "3", "*"
    };

    int ans = obj.evalRPN(tokens);

    cout << "Answer: " << ans << endl;

    return 0;
}