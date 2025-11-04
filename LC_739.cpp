#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        int n = temperatures.size();
        vector<int> ans(n, 0);
        stack<int> st;  // stack will store indices of the temperatures array

        for (int i = 0; i < n; i++) {
            // while current temperature is higher than the temperature at index on top of stack
            while (!st.empty() && temperatures[i] > temperatures[st.top()]) {
                int prevIndex = st.top();
                st.pop();
                ans[prevIndex] = i - prevIndex;  // difference in days
            }
            st.push(i); // push current index
        }

        return ans;
    }
};

int main() {
    Solution sol;
    vector<int> temperatures = {73, 74, 75, 71, 69, 72, 76, 73};

    vector<int> result = sol.dailyTemperatures(temperatures);

    cout << "Result: ";
    for (int x : result)
        cout << x << " ";
    cout << endl;

    return 0;
}
