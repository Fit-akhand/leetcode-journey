#include <algorithm>
class Solution {
public:

    void solve(vector<int>& arr,int target,int i,vector<int>&temp,vector<vector<int>>&ans){
        
        if (target == 0) {
            ans.push_back(temp);
            return;
        }

        if (i >= arr.size() || target < 0) {
            return;
        }

        temp.push_back(arr[i]);
        solve(arr, target - arr[i], i, temp, ans); 
        temp.pop_back();

        
        solve(arr, target, i + 1, temp, ans);

    }

    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> ans;
        vector<int> temp;
        solve(candidates,target,0,temp,ans);
        return ans;
    }
};