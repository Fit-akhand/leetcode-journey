#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> parent;

    int find(int x) {
        if (parent[x] != x)
            parent[x] = find(parent[x]); // path compression
        return parent[x];
    }

    void unite(int x, int y) {
        int px = find(x);
        int py = find(y);
        if (px != py)
            parent[px] = py;
    }

    int minimumHammingDistance(vector<int>& source, vector<int>& target, vector<vector<int>>& allowedSwaps) {
        int n = source.size();
        parent.resize(n);

        // Initialize DSU
        for (int i = 0; i < n; i++)
            parent[i] = i;

        // Build components
        for (auto &sw : allowedSwaps) {
            unite(sw[0], sw[1]);
        }

        // Group indices
        unordered_map<int, vector<int>> groups;
        for (int i = 0; i < n; i++) {
            groups[find(i)].push_back(i);
        }

        int result = 0;

        // Process each group
        for (auto &entry : groups) {
            auto &indices = entry.second;

            unordered_map<int, int> freq;

            // Count source values
            for (int idx : indices) {
                freq[source[idx]]++;
            }

            // Match with target
            for (int idx : indices) {
                if (freq[target[idx]] > 0) {
                    freq[target[idx]]--;
                } else {
                    result++;
                }
            }
        }

        return result;
    }
};

int main() {
    Solution sol;

    // Example input
    vector<int> source = {1, 2, 3, 4};
    vector<int> target = {2, 1, 4, 5};
    vector<vector<int>> allowedSwaps = {{0, 1}, {2, 3}};

    int result = sol.minimumHammingDistance(source, target, allowedSwaps);

    cout << "Minimum Hamming Distance: " << result << endl;

    return 0;
}