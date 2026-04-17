#include <bits/stdc++.h>
using namespace std;

class Solution {
public:

    bool check(vector<int>& curr, vector<int>& prev){
        return (prev[0] <= curr[0] &&
                prev[1] <= curr[1] &&
                prev[2] <= curr[2]);
    }

    int solveUsingTabulation(vector<vector<int>>& nums){
        int n = nums.size();

        vector<int> currRow(n+1, 0);
        vector<int> nextRow(n+1, 0);

        for(int curr = n-1; curr >= 0; curr--){
            for(int prev = curr-1; prev >= -1; prev--){

                int include = 0;
                if(prev == -1 || check(nums[curr], nums[prev])){
                    include = nums[curr][2] + nextRow[curr+1];
                }

                int exclude = nextRow[prev+1];

                currRow[prev+1] = max(include, exclude);
            }
            nextRow = currRow;
        }
        return nextRow[0];
    }

    int maxHeight(vector<vector<int>>& cuboids) {
        // sort each cuboid dimensions
        for(auto &c : cuboids){
            sort(c.begin(), c.end());
        }

        // sort all cuboids
        sort(cuboids.begin(), cuboids.end());

        return solveUsingTabulation(cuboids);
    }
};

int main(){
    int n;
    cout << "Enter number of cuboids: ";
    cin >> n;

    vector<vector<int>> cuboids(n, vector<int>(3));

    cout << "Enter dimensions (l w h):\n";
    for(int i = 0; i < n; i++){
        cin >> cuboids[i][0] >> cuboids[i][1] >> cuboids[i][2];
    }

    Solution obj;
    cout << "Maximum Height: " << obj.maxHeight(cuboids) << endl;

    return 0;
}