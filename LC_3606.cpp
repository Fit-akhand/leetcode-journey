#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<string> validateCoupons(vector<string>& code,
                                   vector<string>& businessLine,
                                   vector<bool>& isActive) {

        // Business line priority
        unordered_map<string, int> priority = {
            {"electronics", 0},
            {"grocery", 1},
            {"pharmacy", 2},
            {"restaurant", 3}
        };

        vector<pair<int, string>> valid; // {business priority, code}

        for (int i = 0; i < code.size(); i++) {
            // Check if active
            if (!isActive[i]) continue;

            // Check valid business line
            if (!priority.count(businessLine[i])) continue;

            // Check non-empty code
            if (code[i].empty()) continue;

            // Check allowed characters
            bool ok = true;
            for (char c : code[i]) {
                if (!(isalnum(c) || c == '_')) {
                    ok = false;
                    break;
                }
            }
            if (!ok) continue;

            valid.push_back({priority[businessLine[i]], code[i]});
        }

        // Sort by businessLine priority, then by code
        sort(valid.begin(), valid.end(),
             [](const pair<int, string>& a, const pair<int, string>& b) {
                 if (a.first != b.first)
                     return a.first < b.first;
                 return a.second < b.second;
             });

        // Extract result
        vector<string> result;
        for (auto &p : valid) {
            result.push_back(p.second);
        }

        return result;
    }
};

int main() {
    Solution sol;

    // Sample input
    vector<string> code = {"SAVE20", "", "PHARMA5", "SAVE@20", "ELECTRONICS_50"};
    vector<string> businessLine = {
        "restaurant", "grocery", "pharmacy", "restaurant", "electronics"
    };
    vector<bool> isActive = {true, true, true, true, true};

    vector<string> result = sol.validateCoupons(code, businessLine, isActive);

    // Print output
    cout << "Valid Coupons:\n";
    for (const string &s : result) {
        cout << s << "\n";
    }

    return 0;
}
