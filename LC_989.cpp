#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> addToArrayForm(vector<int>& num, int k) {
        vector<int> ans;
        reverse(num.begin(), num.end());
        
        int carry = 0;
        int i = 0;

        while(i < num.size() || k > 0 || carry > 0){
            int digitFromK = k % 10;
            int digitFromNum = (i < num.size()) ? num[i] : 0;

            int sum = digitFromNum + digitFromK + carry;

            ans.push_back(sum % 10);
            carry = sum / 10;

            k /= 10;
            i++;
        }

        reverse(ans.begin(), ans.end());
        return ans;
    }
};

int main() {
    Solution s;
    vector<int> num = {1,2,0,0};
    int k = 34;

    vector<int> ans = s.addToArrayForm(num, k);

    for(int x : ans) cout << x << " ";  // Output: 1 2 3 4
    cout << endl;

    return 0;
}
