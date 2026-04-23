#include <iostream>
#include <string>
using namespace std;

class Solution {
public:
    int lengthOfLastWord(string s) {
        int n = s.size();
        int length = 0;

        // Step 1: skip trailing spaces
        int i = n - 1;
        while (i >= 0 && s[i] == ' ') {
            i--;
        }

        // Step 2: count last word
        while (i >= 0 && s[i] != ' ') {
            length++;
            i--;
        }

        return length;
    }
};

int main() {
    Solution obj;

    string s;
    cout << "Enter string: ";
    getline(cin, s);  // allows spaces

    int result = obj.lengthOfLastWord(s);

    cout << "Length of last word: " << result << endl;

    return 0;
}