#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int countTriples(int n) {
        int ans = 0;

        for (int a = 1; a <= n; ++a) {
            for (int b = 1; b <= n; ++b) {
                int c2 = a * a + b * b;
                int c = (int)sqrt(c2);

                if (c <= n && c * c == c2) {
                    ans++;
                }
            }
        }

        return ans;
    }
};

int main() {
    Solution sol;
    int n;
    cin >> n;
    cout << sol.countTriples(n) << endl;
    return 0;
}
