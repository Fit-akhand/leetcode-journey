#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    long long requiredHour(vector<int>& piles, int k) {
        long long hours = 0;

        for (int pile : piles) {
            hours += (pile + k - 1) / k;
        }

        return hours;
    }

    int minEatingSpeed(vector<int>& piles, int h) {
        int low = 1;
        int high = *max_element(piles.begin(), piles.end());

        while (low < high) {
            int mid = low + (high - low) / 2;

            if (requiredHour(piles, mid) <= h) {
                high = mid;
            } 
            else {
                low = mid + 1;
            }
        }

        return low;
    }
};

int main() {
    Solution obj;

    vector<int> piles = {3, 6, 7, 11};
    int h = 8;

    int answer = obj.minEatingSpeed(piles, h);

    cout << "Minimum eating speed: " << answer << endl;

    return 0;
}