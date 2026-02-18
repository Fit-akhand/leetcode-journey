#include <iostream>
#include <vector>
#include <queue>
using namespace std;

class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        int n = nums.size();
        priority_queue<int, vector<int>, greater<int>> pq;

        // Push first k elements
        for (int i = 0; i < k; i++) {
            pq.push(nums[i]);
        }

        // Process remaining elements
        for (int i = k; i < n; i++) {
            if (nums[i] > pq.top()) {
                pq.pop();
                pq.push(nums[i]);
            }
        }
        return pq.top();
    }
};

int main() {
    Solution sol;

    vector<int> nums = {3, 2, 1, 5, 6, 4};
    int k = 2;

    int result = sol.findKthLargest(nums, k);
    cout << "Kth largest element: " << result << endl;

    return 0;
}
