#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>

using namespace std;

class Solution {
public:
    vector<int> arrayRankTransform(vector<int>& arr) {

        vector<int> temp = arr;

        sort(temp.begin(), temp.end());

        unordered_map<int, int> rank;
        int r = 1;

        // Assign ranks to unique elements
        for (int x : temp) {
            if (rank.find(x) == rank.end()) {
                rank[x] = r++;
            }
        }

        // Replace elements with their ranks
        for (int i = 0; i < arr.size(); i++) {
            arr[i] = rank[arr[i]];
        }

        return arr;
    }
};

int main() {

    int n;

    cout << "Enter size of array: ";
    cin >> n;

    vector<int> arr(n);

    cout << "Enter elements: ";
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    Solution obj;

    vector<int> ans = obj.arrayRankTransform(arr);

    cout << "Rank Transformed Array: ";

    for (int x : ans) {
        cout << x << " ";
    }

    cout << endl;

    return 0;
}