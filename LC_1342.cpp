#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int numberOfSteps(int num) {
        int count = 0;
        while(num != 0) {
            if(num % 2 == 0) {
                num = num / 2;
            } else {
                num = num - 1;
            }
            count++;
        }
        return count;
    }
};

int main() {
    Solution sol;
    int num = 14;

    int result = sol.numberOfSteps(num);
    cout << "Number of steps: " << result << endl;

    return 0;
}
