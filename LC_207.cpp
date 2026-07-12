#include <iostream>
#include <vector>
#include <unordered_map>
#include <queue>

using namespace std;

class Solution {
public:

    void solve(int V, unordered_map<int, vector<int>>& adjList, vector<int>& ans) {

        unordered_map<int, int> indegree;
        queue<int> q;

        // Initialize indegree
        for (int i = 0; i < V; i++) {
            indegree[i] = 0;
        }

        // Calculate indegree
        for (auto &src : adjList) {
            for (int nbr : src.second) {
                indegree[nbr]++;
            }
        }

        // Push all nodes having indegree 0
        for (int i = 0; i < V; i++) {
            if (indegree[i] == 0)
                q.push(i);
        }

        // Kahn's Algorithm
        while (!q.empty()) {

            int front = q.front();
            q.pop();

            ans.push_back(front);

            for (int nbr : adjList[front]) {
                indegree[nbr]--;

                if (indegree[nbr] == 0)
                    q.push(nbr);
            }
        }
    }

    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {

        unordered_map<int, vector<int>> adjList;

        // Build graph: prerequisite -> course
        for (auto &edge : prerequisites) {
            int u = edge[1];
            int v = edge[0];

            adjList[u].push_back(v);
        }

        vector<int> ans;

        solve(numCourses, adjList, ans);

        return ans.size() == numCourses;
    }
};

int main() {

    int numCourses, m;

    cout << "Enter number of courses: ";
    cin >> numCourses;

    cout << "Enter number of prerequisite pairs: ";
    cin >> m;

    vector<vector<int>> prerequisites;

    cout << "Enter prerequisite pairs (course prerequisite):\n";

    for (int i = 0; i < m; i++) {
        int a, b;
        cin >> a >> b;
        prerequisites.push_back({a, b});
    }

    Solution obj;

    if (obj.canFinish(numCourses, prerequisites))
        cout << "Yes, all courses can be completed.\n";
    else
        cout << "No, all courses cannot be completed.\n";

    return 0;
}