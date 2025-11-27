#include <iostream>
using namespace std;

class Solution {
public:
    int climbStairs(int n) {
        int a = 1;
        int b = 2;
        int ans = 0;

        if (n == 1) return a;
        if (n == 2) return b;

        for (int i = 3; i <= n; i++) {
            ans = a + b;
            a = b;
            b = ans;
        }
        return ans;
    }
};

int main() {
    Solution obj;
    int n;
    cout << "Enter number of stairs: ";
    cin >> n;

    cout << "Ways to climb stairs = " << obj.climbStairs(n) << endl;

    return 0;
}
