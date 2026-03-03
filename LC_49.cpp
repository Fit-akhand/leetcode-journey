#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>
#include <algorithm>

using namespace std;

class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string, vector<string>> m;

        for (int i = 0; i < strs.size(); i++) {
            string element = strs[i];
            string temp = element;
            sort(temp.begin(), temp.end());
            m[temp].push_back(element);
        }

        vector<vector<string>> ans;
        for (auto i : m) {
            ans.push_back(i.second);
        }

        return ans;
    }
};

int main() {
    Solution sol;

    vector<string> input = {"eat", "tea", "tan", "ate", "nat", "bat"};
    vector<vector<string>> result = sol.groupAnagrams(input);

    for (auto group : result) {
        for (auto word : group) {
            cout << word << " ";
        }
        cout << endl;
    }

    return 0;
}