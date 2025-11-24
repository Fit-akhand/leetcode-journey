#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int averageValue(vector<int>& nums) {
        int sum = 0;
        int count = 0;
        
        for(int x : nums) {
            if(x % 6 == 0) { // divisible by 2 and 3 → divisible by 6
                sum += x;
                count++;
            }
        }

        return (count == 0) ? 0 : sum / count;
    }
};

int main() {
    Solution obj;

    int n;
    cout << "Enter number of elements: ";
    cin >> n;

    vector<int> nums(n);
    cout << "Enter elements: ";
    for(int i = 0; i < n; i++) {
        cin >> nums[i];
    }

    int result = obj.averageValue(nums);
    cout << "Average Value: " << result << endl;

    return 0;
}
