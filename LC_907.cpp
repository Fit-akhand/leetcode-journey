#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    // Function to find Next Smaller Element indices
    vector<int> nextsmallerelement(vector<int>& v) {
        int n = v.size();
        vector<int> next(n, -1);
        stack<int> st;

        for (int i = 0; i < n; i++) {
            while (!st.empty() && v[st.top()] > v[i]) {
                next[st.top()] = i;
                st.pop();
            }
            st.push(i);
        }
        return next;
    }

    // Function to find Previous Smaller Element indices
    vector<int> prevsmallerelement(vector<int>& v) {
        int n = v.size();
        vector<int> prev(n, -1);
        stack<int> st;

        for (int i = n - 1; i >= 0; i--) {
            while (!st.empty() && v[st.top()] >= v[i]) {
                prev[st.top()] = i;
                st.pop();
            }
            st.push(i);
        }
        return prev;
    }

    int sumSubarrayMins(vector<int>& arr) {
        auto next = nextsmallerelement(arr);
        auto prev = prevsmallerelement(arr);
        long long sum = 0;
        const int mod = 1e9 + 7;

        for (int i = 0; i < arr.size(); i++) {
            int nexti = next[i] == -1 ? arr.size() : next[i];
            int previ = prev[i];
            long long left = i - previ;
            long long right = nexti - i;
            long long no_of_times = (left * right) % mod;
            long long total = (no_of_times * arr[i]) % mod;
            sum = (sum + total) % mod;
        }
        return sum;
    }
};

// Example usage for VS Code
int main() {
    Solution s;
    vector<int> arr = {3, 1, 2, 4};
    cout << "Sum of Subarray Minimums: " << s.sumSubarrayMins(arr) << endl;  // Expected: 17
    return 0;
}
