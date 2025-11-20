#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    vector<int> replaceElements(vector<int>& arr) {
        int n = arr.size();
        vector<int> ans(n);
        int maxright = -1;
        for(int i = n-1;i>=0;i--){
            int current = arr[i];
            ans[i] = maxright;
            maxright = max(maxright,current);
        }
        return ans;
    }
};

int main() {
    Solution s;
    vector<int> arr = {17, 18, 5, 4, 6, 1};

    vector<int> ans = s.replaceElements(arr);

    for (int x : ans) {
        cout << x << " ";
    }

    return 0;
}
