#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> frequencySort(vector<int>& nums) {
        int n = nums.size();
        sort(nums.begin(), nums.end());

        vector<pair<int,int>> temp;
        int count = 1;

        for(int i = 1; i < n; i++){
            if(nums[i] == nums[i-1]) {
                count++;
            } else {
                temp.push_back({nums[i-1], count});
                count = 1;
            }
        }

        // push last element group
        temp.push_back({nums[n-1], count});

        // Sort by: freq asc, value desc
        sort(temp.begin(), temp.end(), [](auto &a, auto &b){
            if(a.second == b.second)
                return a.first > b.first; // higher value first
            return a.second < b.second;     // lower freq first
        });

        vector<int> ans;

        for(auto &p : temp) {
            while(p.second--) {
                ans.push_back(p.first);
            }
        }

        return ans;
    }
};

int main() {
    int n;
    cin >> n;

    vector<int> nums(n);
    for(int i = 0; i < n; i++)
        cin >> nums[i];

    Solution obj;
    vector<int> result = obj.frequencySort(nums);

    for(int x : result)
        cout << x << " ";
    cout << endl;

    return 0;
}
