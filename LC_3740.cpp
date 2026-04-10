#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int minimumDistance(vector<int>& nums) {
        unordered_map<int, vector<int>> pos;
        
        // Store indices of each number
        for (int i = 0; i < nums.size(); i++) {
            pos[nums[i]].push_back(i);
        }
        
        int ans = INT_MAX;
        
        // Process each value's index list
        for (auto &p : pos) {
            vector<int> &indices = p.second;
            
            if (indices.size() >= 3) {
                for (int i = 0; i + 2 < indices.size(); i++) {
                    int dist = 2 * (indices[i + 2] - indices[i]);
                    ans = min(ans, dist);
                }
            }
        }
        
        return (ans == INT_MAX) ? -1 : ans;
    }
};

int main() {
    int n;
    cout << "Enter size of array: ";
    cin >> n;

    vector<int> nums(n);
    cout << "Enter elements: ";
    for (int i = 0; i < n; i++) {
        cin >> nums[i];
    }

    Solution sol;
    int result = sol.minimumDistance(nums);

    cout << "Minimum Distance: " << result << endl;

    return 0;
}