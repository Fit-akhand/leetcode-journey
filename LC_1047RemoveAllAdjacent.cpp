#include <iostream>
#include <stack>
#include <algorithm>
using namespace std;

class Solution {
public:
    string removeDuplicates(string s) {
        stack<char> st;
        int n = s.length();
        for(int i=0;i<n;i++){
            char ch = s[i];
            if(!st.empty() && st.top() == ch){
                st.pop();
            }
            else{
                st.push(ch);
            }
        }

        string str;
        while(!st.empty()){
            str.push_back(st.top());
            st.pop();
        }

        reverse(str.begin(), str.end());
        return str;
    }
};

int main() {
    Solution sol;
    string s;
    cout << "Enter string: ";
    cin >> s;
    cout << "Result: " << sol.removeDuplicates(s) << endl;
    return 0;
}
