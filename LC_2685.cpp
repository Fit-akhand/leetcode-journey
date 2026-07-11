#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    vector<vector<int>> adj;
    vector<int> vis;

    void dfs(int node, int &vertices, int &degreeSum) {
        vis[node] = 1;
        vertices++;
        degreeSum += adj[node].size();

        for (int nei : adj[node]) {
            if (!vis[nei]) {
                dfs(nei, vertices, degreeSum);
            }
        }
    }

    int countCompleteComponents(int n, vector<vector<int>>& edges) {
        adj.clear();
        adj.resize(n);
        vis.assign(n, 0);

        for (auto &e : edges) {
            int u = e[0];
            int v = e[1];

            adj[u].push_back(v);
            adj[v].push_back(u);
        }

        int ans = 0;

        for (int i = 0; i < n; i++) {
            if (!vis[i]) {
                int vertices = 0;
                int degreeSum = 0;

                dfs(i, vertices, degreeSum);

                int edgeCount = degreeSum / 2;
                int requiredEdges = vertices * (vertices - 1) / 2;

                if (edgeCount == requiredEdges)
                    ans++;
            }
        }

        return ans;
    }
};

int main() {
    Solution obj;

    int n, m;
    cin >> n >> m;

    vector<vector<int>> edges;

    for (int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;
        edges.push_back({u, v});
    }

    cout << obj.countCompleteComponents(n, edges) << endl;

    return 0;
}