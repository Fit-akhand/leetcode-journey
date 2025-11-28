#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int ans = 0;
    vector<vector<int>> adj;

    long long dfs(int node, int parent, vector<int>& values, int k) {
        long long sum = values[node];

        for (int child : adj[node]) {
            if (child == parent) continue;
            sum += dfs(child, node, values, k);
        }

        if (sum % k == 0) {
            ans++;
            return 0;
        }

        return sum;
    }

    int maxKDivisibleComponents(int n, vector<vector<int>>& edges, vector<int>& values, int k) {
        adj.clear();
        adj.resize(n);

        for (auto &e : edges) {
            int a = e[0], b = e[1];
            adj[a].push_back(b);
            adj[b].push_back(a);
        }

        dfs(0, -1, values, k);
        return ans;
    }
};

// ========== Main function for VS Code ==========
int main() {
    int n, k;
    cout << "Enter n and k: ";
    cin >> n >> k;

    vector<int> values(n);
    cout << "Enter " << n << " node values:\n";
    for (int i = 0; i < n; i++) cin >> values[i];

    vector<vector<int>> edges(n - 1, vector<int>(2));
    cout << "Enter " << n - 1 << " edges (u v):\n";
    for (int i = 0; i < n - 1; i++) {
        cin >> edges[i][0] >> edges[i][1];
    }

    Solution s;
    int result = s.maxKDivisibleComponents(n, edges, values, k);

    cout << "\nMaximum K-Divisible Components = " << result << endl;

    return 0;
}
