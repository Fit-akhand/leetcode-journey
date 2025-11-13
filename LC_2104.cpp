#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    // Next Smaller Element (NGE)
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

    // Previous Smaller Element
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

    long long sumSubarrayMins(vector<int>& arr) {
        auto next = nextsmallerelement(arr);
        auto prev = prevsmallerelement(arr);

        long long sum = 0;

        for (int i = 0; i < arr.size(); i++) {
            int nexti = next[i] == -1 ? arr.size() : next[i];
            int previ = prev[i];

            long long left = i - previ;
            long long right = nexti - i;

            long long times = left * right;
            sum += (times * arr[i]);
        }
        return sum;
    }

    // Next Greater Element
    vector<int> nextgraterelement(vector<int>& v) {
        int n = v.size();
        vector<int> next(n, -1);
        stack<int> st;

        for (int i = 0; i < n; i++) {
            while (!st.empty() && v[st.top()] < v[i]) {
                next[st.top()] = i;
                st.pop();
            }
            st.push(i);
        }
        return next;
    }

    // Previous Greater Element
    vector<int> prevgraterelement(vector<int>& v) {
        int n = v.size();
        vector<int> prev(n, -1);
        stack<int> st;

        for (int i = n - 1; i >= 0; i--) {
            while (!st.empty() && v[st.top()] <= v[i]) {
                prev[st.top()] = i;
                st.pop();
            }
            st.push(i);
        }
        return prev;
    }

    long long sumSubarrayMaxs(vector<int>& arr) {
        auto next = nextgraterelement(arr);
        auto prev = prevgraterelement(arr);

        long long sum = 0;

        for (int i = 0; i < arr.size(); i++) {
            int nexti = next[i] == -1 ? arr.size() : next[i];
            int previ = prev[i];

            long long left = i - previ;
            long long right = nexti - i;

            long long times = left * right;
            sum += (times * arr[i]);
        }
        return sum;
    }

    long long subArrayRanges(vector<int>& nums) {
        long long mn = sumSubarrayMins(nums);
        long long mx = sumSubarrayMaxs(nums);
        return mx - mn;
    }
};


// Optional main to test in VS Code
int main() {
    Solution s;
    vector<int> nums = {1, 2, 3};
    cout << s.subArrayRanges(nums);
    return 0;
}
