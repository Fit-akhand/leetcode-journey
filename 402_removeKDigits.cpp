#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    string removeKdigits(string num, int k) {
        if (num.size() == k) {
            return "0";
        }

        string s;
        for (char digit : num) {
            while (!s.empty() && k > 0 && s.back() > digit) {
                s.pop_back();
                k--;
            }
            s.push_back(digit);
        }

        // If still k left, remove from end
        while (k > 0 && !s.empty()) {
            s.pop_back();
            k--;
        }

        // Remove leading zeros
        int i = 0;
        while (i < s.size() && s[i] == '0') i++;

        string ans = s.substr(i);
        return ans.empty() ? "0" : ans;
    }
};

int main() {
    Solution sol;
    string num;
    int k;
    
    cout << "Enter number string: ";
    cin >> num;
    cout << "Enter k: ";
    cin >> k;
    
    cout << "Smallest number after removing " << k << " digits: " 
         << sol.removeKdigits(num, k) << endl;
    
    return 0;
}
