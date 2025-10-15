#include <iostream>
#include <vector>
#include <stack>
#include <algorithm>
using namespace std;

class Solution {
public:

    // Find index of next smaller element for each bar
    void nextSmaller(vector<int>& heights, vector<int>& nextans) {
        stack<int> st;
        st.push(-1);
        int n = heights.size();

        for(int i = n - 1; i >= 0; i--) {
            int element = heights[i];
            while(st.top() != -1 && heights[st.top()] >= element) {
                st.pop();
            }
            nextans.push_back(st.top());
            st.push(i);
        }
        // reverse because we traversed from right to left
        reverse(nextans.begin(), nextans.end());

        // Replace -1 with size of array for bars without a smaller element on right
        for(int i = 0; i < nextans.size(); i++) {
            if(nextans[i] == -1) {
                nextans[i] = n;
            }
        }
    }

    // Find index of previous smaller element for each bar
    void prevSmaller(vector<int>& heights, vector<int>& prevans) {
        stack<int> st;
        st.push(-1);
        int n = heights.size();

        for(int i = 0; i < n; i++) {
            int element = heights[i];
            while(st.top() != -1 && heights[st.top()] >= element) {
                st.pop();
            }
            prevans.push_back(st.top());
            st.push(i);
        }
    }

    int largestRectangleArea(vector<int>& heights) {
        int n = heights.size();
        vector<int> nextans, prevans;

        nextSmaller(heights, nextans);
        prevSmaller(heights, prevans);

        int maxArea = 0;
        for(int i = 0; i < n; i++) {
            int width = nextans[i] - prevans[i] - 1;
            int height = heights[i];
            maxArea = max(maxArea, width * height);
        }

        return maxArea;
    }
};

int main() {
    Solution sol;
    vector<int> heights = {2,1,5,6,2,3};
    cout << "Largest Rectangle Area: " << sol.largestRectangleArea(heights) << endl;
    return 0;
}
