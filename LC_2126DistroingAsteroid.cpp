#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool asteroidsDestroyed(int mass, vector<int>& asteroids) {
        sort(asteroids.begin(), asteroids.end());
        int n = asteroids.size();
        long long a = mass; // use long long to avoid overflow
        for (int i = 0; i < n; i++) {
            if (a >= asteroids[i]) {
                a += asteroids[i];
            } else {
                return false;
            }
        }
        return true;
    }
};

int main() {
    Solution sol;

    // Example test case
    int mass = 10;
    vector<int> asteroids = {3, 9, 19, 5, 21};

    bool result = sol.asteroidsDestroyed(mass, asteroids);

    if (result)
        cout << "✅ Planet survives and destroys all asteroids!" << endl;
    else
        cout << "❌ Planet destroyed!" << endl;

    return 0;
}
