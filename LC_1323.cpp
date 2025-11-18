#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maximum69Number (int num) {
        string s = to_string(num);
        for(char &c : s) {
            if(c == '6') {
                c = '9';
                break;
            }
        }
        return stoi(s);
    }
};

int main() {
    Solution obj;
    int num;
    cout << "Enter a number (only digits 6 & 9): ";
    cin >> num;

    cout << "Maximum number possible: " << obj.maximum69Number(num) << endl;
    return 0;
}
