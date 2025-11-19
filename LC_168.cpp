#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    string convertToTitle(int columnNumber) {
        string ans = "";
        while(columnNumber != 0){
            
            int ch = columnNumber % 26;  // remainder

            if(ch == 0){
                ans.push_back('Z');
                columnNumber = (columnNumber / 26) - 1;  // important fix
            }
            else{
                ans.push_back('A' + ch - 1); // convert to letter
                columnNumber /= 26;
            }
        }

        reverse(ans.begin(), ans.end());
        return ans;
    }
};

int main() {
    Solution s;

    // Test cases
    cout << s.convertToTitle(1) << endl;       // A
    cout << s.convertToTitle(26) << endl;      // Z
    cout << s.convertToTitle(27) << endl;      // AA
    cout << s.convertToTitle(52) << endl;      // AZ
    cout << s.convertToTitle(701) << endl;     // ZY
    cout << s.convertToTitle(702) << endl;     // ZZ
    cout << s.convertToTitle(703) << endl;     // AAA

    return 0;
}
