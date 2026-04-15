    #include <bits/stdc++.h>
using namespace std;

class Solution {
public:

    int solveUsingRecursion(vector<int>& arr, map<pair<int,int>,int>& maxi, int left, int right){
        if(left == right){
            return 0; 
        }
        int ans = INT_MAX;
        for(int i = left; i < right; i++){
            ans = min(ans,
                maxi[{left,i}] * maxi[{i+1,right}] +
                solveUsingRecursion(arr,maxi,left,i) +
                solveUsingRecursion(arr,maxi,i+1,right)
            );  
        }
        return ans;
    }

    int solveUsingMem(vector<int>& arr, map<pair<int,int>,int>& maxi, int left, int right, vector<vector<int>>& dp){
        if(left == right){
            return 0; 
        }
        if(dp[left][right] != -1){
            return dp[left][right];
        }
        int ans = INT_MAX;
        for(int i = left; i < right; i++){
            ans = min(ans,
                maxi[{left,i}] * maxi[{i+1,right}] +
                solveUsingMem(arr,maxi,left,i,dp) +
                solveUsingMem(arr,maxi,i+1,right,dp)
            );  
        }
        dp[left][right] = ans;
        return ans;
    }

    int solveByTab(vector<int>& arr, map<pair<int,int>,int>& maxi){
        int n = arr.size();
        vector<vector<int>> dp(n, vector<int>(n, 0));

        for(int left = n-1; left >= 0; left--){
            for(int right = left+1; right < n; right++){
                int ans = INT_MAX;
                for(int i = left; i < right; i++){
                    ans = min(ans,
                        maxi[{left,i}] * maxi[{i+1,right}] +
                        dp[left][i] +
                        dp[i+1][right]
                    );  
                }
                dp[left][right] = ans;
            }
        }
        return dp[0][n-1];
    }

    int mctFromLeafValues(vector<int>& arr) {
        map<pair<int,int>,int> maxi;

        for(int i = 0; i < arr.size(); i++){
            maxi[{i,i}] = arr[i];
            for(int j = i+1; j < arr.size(); j++){
                maxi[{i,j}] = max(arr[j], maxi[{i,j-1}]);
            }
        }

        // Choose method:
        // return solveUsingRecursion(arr,maxi,0,arr.size()-1);

        // vector<vector<int>> dp(arr.size(), vector<int>(arr.size(), -1));
        // return solveUsingMem(arr,maxi,0,arr.size()-1,dp);

        return solveByTab(arr,maxi);
    }
};

int main() {
    int n;
    cout << "Enter size of array: ";
    cin >> n;

    vector<int> arr(n);
    cout << "Enter elements: ";
    for(int i = 0; i < n; i++){
        cin >> arr[i];
    }

    Solution obj;
    cout << "Minimum Cost Tree: " << obj.mctFromLeafValues(arr) << endl;

    return 0;
}