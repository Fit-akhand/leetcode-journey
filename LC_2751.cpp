#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> survivedRobotsHealths(vector<int>& positions, vector<int>& healths, string directions) {
        int n = positions.size();
        
        vector<tuple<int, int, char, int>> robots;
        for (int i = 0; i < n; i++) {
            robots.push_back({positions[i], healths[i], directions[i], i});
        }
        
        sort(robots.begin(), robots.end());
        
        stack<int> st;
        vector<int> currHealth(n);
        
        for (int i = 0; i < n; i++) {
            currHealth[i] = get<1>(robots[i]);
        }
        
        for (int i = 0; i < n; i++) {
            char dir = get<2>(robots[i]);
            
            if (dir == 'R') {
                st.push(i);
            } else {
                while (!st.empty() && currHealth[i] > 0) {
                    int j = st.top();
                    
                    if (currHealth[j] < currHealth[i]) {
                        st.pop();
                        currHealth[i]--;
                        currHealth[j] = 0;
                    } 
                    else if (currHealth[j] > currHealth[i]) {
                        currHealth[j]--;
                        currHealth[i] = 0;
                    } 
                    else {
                        st.pop();
                        currHealth[j] = 0;
                        currHealth[i] = 0;
                        break;
                    }
                }
            }
        }
        
        vector<pair<int, int>> survivors;
        
        for (int i = 0; i < n; i++) {
            if (currHealth[i] > 0) {
                int originalIndex = get<3>(robots[i]);
                survivors.push_back({originalIndex, currHealth[i]});
            }
        }
        
        sort(survivors.begin(), survivors.end());
        
        vector<int> result;
        for (auto &p : survivors) {
            result.push_back(p.second);
        }
        
        return result;
    }
};

int main() {
    Solution sol;

    // Example input
    vector<int> positions = {3, 5, 2, 6};
    vector<int> healths = {10, 10, 15, 12};
    string directions = "RLRL";

    vector<int> result = sol.survivedRobotsHealths(positions, healths, directions);

    cout << "Survived Robots Healths: ";
    for (int h : result) {
        cout << h << " ";
    }
    cout << endl;

    return 0;
}