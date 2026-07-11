#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    int maxArea(vector<int>& height) {

        int left = 0;
        int right = height.size() - 1;

        int ans = 0;

        while (left < right) {

            int width = right - left;
            int h = min(height[left], height[right]);

            ans = max(ans, width * h);

            if (height[left] < height[right])
                left++;
            else
                right--;
        }

        return ans;
    }
};

int main() {

    int n;

    cout << "Enter number of heights: ";
    cin >> n;

    vector<int> height(n);

    cout << "Enter heights: ";
    for (int i = 0; i < n; i++) {
        cin >> height[i];
    }

    Solution obj;

    cout << "Maximum Water = " << obj.maxArea(height) << endl;

    return 0;
}