#include <bits/stdc++.h>
using namespace std;

class Solution {
public:

    int reverseNum(int num){
        int a = 0;
        while(num != 0){
            int k = num % 10;
            a = a * 10 + k;
            num = num / 10;
        }
        return a;
    }

    int minMirrorPairDistance(vector<int>& nums) {
        int n = nums.size();
        int ans = INT_MAX;

        unordered_map<int, int> mp;

        for(int i = 0; i < n; i++){
            int rev = reverseNum(nums[i]);

            // Check if reverse already seen
            if(mp.find(nums[i]) != mp.end()){
                ans = min(ans, i - mp[nums[i]]);
            }

            // Store reverse for future matches
            mp[rev] = i;
        }

        if(ans == INT_MAX){
            return -1;
        }
        return ans;
    }
};

int main() {
    Solution obj;

    int n;
    cout << "Enter size: ";
    cin >> n;

    vector<int> nums(n);
    cout << "Enter elements: ";
    for(int i = 0; i < n; i++){
        cin >> nums[i];
    }

    int result = obj.minMirrorPairDistance(nums);

    cout << "Minimum Mirror Pair Distance: " << result << endl;

    return 0;
}