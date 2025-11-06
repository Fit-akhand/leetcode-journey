#include <bits/stdc++.h>   // includes all standard C++ libraries
using namespace std;

class Solution {
public:
    vector<int> asteroidCollision(vector<int>& asteroids) {
        vector<int> st;  // using vector as stack

        for (auto a : asteroids) {
            bool explod = false;

            // check collisions only if last asteroid goes right and current one goes left
            while (!st.empty() && a < 0 && st.back() > 0) {
                if (abs(a) > st.back()) {
                    st.pop_back(); // smaller right asteroid destroyed
                    continue;
                } 
                else if (abs(a) == st.back()) {
                    explod = true; // both destroyed
                    st.pop_back();
                    break;
                } 
                else {
                    explod = true; // current left asteroid destroyed
                    break;
                }
            }

            if (!explod) st.push_back(a);
        }

        return st;
    }
};

int main() {
    Solution sol;

    // 🧪 Test Case 1
    vector<int> asteroids1 = {5, 10, -5};
    vector<int> res1 = sol.asteroidCollision(asteroids1);
    cout << "Test 1 Output: ";
    for (int x : res1) cout << x << " ";
    cout << "\n";

    // 🧪 Test Case 2
    vector<int> asteroids2 = {8, -8};
    vector<int> res2 = sol.asteroidCollision(asteroids2);
    cout << "Test 2 Output: ";
    for (int x : res2) cout << x << " ";
    cout << "\n";

    // 🧪 Test Case 3
    vector<int> asteroids3 = {10, 2, -5};
    vector<int> res3 = sol.asteroidCollision(asteroids3);
    cout << "Test 3 Output: ";
    for (int x : res3) cout << x << " ";
    cout << "\n";

    // 🧪 Test Case 4
    vector<int> asteroids4 = {-2, -1, 1, 2};
    vector<int> res4 = sol.asteroidCollision(asteroids4);
    cout << "Test 4 Output: ";
    for (int x : res4) cout << x << " ";
    cout << "\n";

    return 0;
}
