#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> pascal(numRows);

        for (int i = 0; i < numRows; i++) {
            pascal[i].resize(i + 1);
            pascal[i][0] = pascal[i][i] = 1;

            for (int j = 1; j < i; j++) {
                pascal[i][j] = pascal[i - 1][j - 1] + pascal[i - 1][j];
            }
        }

        return pascal;
    }
};

int main() {
    Solution sol;
    int numRows;

    cout << "Enter number of rows: ";
    cin >> numRows;

    vector<vector<int>> result = sol.generate(numRows);

    cout << "\nPascal's Triangle:\n";
    for (auto &row : result) {
        for (auto &val : row) {
            cout << val << " ";
        }
        cout << endl;
    }

    return 0;
}
