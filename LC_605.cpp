#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool canPlaceFlowers(vector<int>& flowerbed, int n) {
        int size = flowerbed.size();

        for (int i = 0; i < size && n > 0; i++) {
            if (flowerbed[i] == 0) {
                bool emptyLeft  = (i == 0) || (flowerbed[i - 1] == 0);
                bool emptyRight = (i == size - 1) || (flowerbed[i + 1] == 0);

                if (emptyLeft && emptyRight) {
                    flowerbed[i] = 1; // plant a flower
                    n--;
                    i++; // skip next spot
                }
            }
        }

        return n == 0;
    }
};

int main() {
    Solution sol;

    vector<int> flowerbed = {1, 0, 0, 0, 1};
    int n = 1;

    bool result = sol.canPlaceFlowers(flowerbed, n);

    if (result)
        cout << "✅ Can place all flowers" << endl;
    else
        cout << "❌ Cannot place all flowers" << endl;

    return 0;
}
