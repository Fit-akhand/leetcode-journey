#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    bool isIsomorphic(const string& s, const string& t) {
        if (s.size() != t.size()) return false;

        vector<int> mapST(256, -1); // s -> t
        vector<int> mapTS(256, -1); // t -> s

        for (int i = 0; i < s.size(); i++) {
            unsigned char c1 = s[i];
            unsigned char c2 = t[i];

            if (mapST[c1] == -1 && mapTS[c2] == -1) {
                mapST[c1] = c2;
                mapTS[c2] = c1;
            } 
            else {
                if (mapST[c1] != c2 || mapTS[c2] != c1)
                    return false;
            }
        }
        return true;
    }
};

int main() {
    Solution sol;
    string s, t;

    cout << "Enter string s: ";
    cin >> s;
    cout << "Enter string t: ";
    cin >> t;

    if (sol.isIsomorphic(s, t))
        cout << "Yes, strings are isomorphic.\n";
    else
        cout << "No, strings are not isomorphic.\n";

    return 0;
}
