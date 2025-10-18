#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Solution {
public:
    string simplifyPath(string path) {
        vector<string> st;
        string token = "";

        for (int i = 0; i <= path.size(); i++) {
            // End of a directory name or end of string
            if (i == path.size() || path[i] == '/') {
                if (token == "" || token == ".") {
                    // skip empty or current dir
                } 
                else if (token == "..") {
                    // go up one directory
                    if (!st.empty()) st.pop_back();
                } 
                else {
                    // normal directory name
                    st.push_back(token);
                }
                token = ""; // reset token
            } 
            else {
                token += path[i]; // build current directory name
            }
        }

        // Build the simplified path
        string result = "/";
        for (int i = 0; i < st.size(); i++) {
            result += st[i];
            if (i != st.size() - 1) result += "/";
        }

        return result;
    }
};

int main() {
    Solution sol;

    string path;
    cout << "Enter a path: ";
    cin >> path;

    cout << "Simplified Path: " << sol.simplifyPath(path) << endl;

    return 0;
}
