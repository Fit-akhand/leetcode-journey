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
        for (auto edge : adjList) {
            for (int nbr : edge.second) {
                indegree[nbr]++;
            }
        }

        // Push all nodes having indegree 0
        for (int i = 0; i < V; i++) {
            if (indegree[i] == 0) {
                q.push(i);
            }
        }

        // Kahn's Algorithm
        while (!q.empty()) {

            int front = q.front();
            q.pop();

            ans.push_back(front);

            for (int nbr : adjList[front]) {
                indegree[nbr]--;

                if (indegree[nbr] == 0) {
                    q.push(nbr);
                }
            }
        }
    }

    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {

        unordered_map<int, vector<int>> adjList;

        // prerequisite -> course
        for (auto edge : prerequisites) {
            int u = edge[1];
            int v = edge[0];

            adjList[u].push_back(v);
        }

        vector<int> ans;

        solve(numCourses, adjList, ans);

        if (ans.size() == numCourses)
            return ans;

        return {};
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
        int course, prerequisite;
        cin >> course >> prerequisite;

        prerequisites.push_back({course, prerequisite});
    }

    Solution obj;

    vector<int> order = obj.findOrder(numCourses, prerequisites);

    if (order.empty()) {
        cout << "No valid ordering exists (cycle detected)." << endl;
    } else {
        cout << "Course Order: ";

        for (int x : order)
            cout << x << " ";

        cout << endl;
    }

    return 0;
}