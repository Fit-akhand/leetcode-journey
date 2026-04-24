#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int furthestDistanceFromOrigin(string moves) {
        int l = 0, r = 0, u = 0;
        
        for (char c : moves) {
            if (c == 'L') l++;
            else if (c == 'R') r++;
            else u++; // '_'
        }
        
        return abs(r - l) + u;
    }
};

int main() {
    Solution obj;
    
    string moves;
    cout << "Enter moves string: ";
    cin >> moves;

    int result = obj.furthestDistanceFromOrigin(moves);
    
    cout << "Furthest distance from origin: " << result << endl;

    return 0;
}