#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maxDistance(vector<int>& colors) {
        int maxDis = INT_MIN;
        int n = colors.size();

        for(int i = 1; i < n; i++) {
            for(int j = 0; j < i; j++) {
                if(colors[i] != colors[j]) {
                    int dis = i - j;
                    if(dis > maxDis) {
                        maxDis = dis;
                    }
                }
            }
        }
        return maxDis;
    }
};

int main() {
    Solution obj;
    vector<int> colors = {1,1,2,3,1,2};

    cout << "Max Distance: " << obj.maxDistance(colors);

    return 0;
}