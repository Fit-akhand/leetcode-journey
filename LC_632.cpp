#include <bits/stdc++.h>
using namespace std;

class Info {
public:
    int data;
    int rIndex;
    int cIndex;

    Info(int a, int b, int c) {
        data = a;
        rIndex = b;
        cIndex = c;
    }
};

class compare {
public:
    bool operator()(const Info& a, const Info& b) const {
        return a.data > b.data;
    }
};

class Solution {
public:
    vector<int> smallestRange(vector<vector<int>>& nums) {

        priority_queue<Info, vector<Info>, compare> pq;

        int maxi = INT_MIN;
        int mini = INT_MAX;

        for (int i = 0; i < nums.size(); i++) {
            pq.push(Info(nums[i][0], i, 0));
            maxi = max(maxi, nums[i][0]);
            mini = min(mini, nums[i][0]);
        }

        int start = mini, end = maxi;

        while (!pq.empty()) {
            Info cur = pq.top();
            pq.pop();

            mini = cur.data;

            if (maxi - mini < end - start) {
                start = mini;
                end = maxi;
            }

            if (cur.cIndex + 1 < nums[cur.rIndex].size()) {
                int nextVal = nums[cur.rIndex][cur.cIndex + 1];
                maxi = max(maxi, nextVal);
                pq.push(Info(nextVal, cur.rIndex, cur.cIndex + 1));
            } else {
                break;
            }
        }

        return {start, end};
    }
};

int main() {
    Solution sol;

    vector<vector<int>> nums = {
        {4, 10, 15, 24, 26},
        {0, 9, 12, 20},
        {5, 18, 22, 30}
    };

    vector<int> result = sol.smallestRange(nums);

    cout << "Smallest Range: [" << result[0] << ", " << result[1] << "]" << endl;

    return 0;
}