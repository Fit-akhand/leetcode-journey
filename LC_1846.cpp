#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int maximumElementAfterDecrementingAndRearranging(vector<int>& arr) {
    sort(arr.begin(), arr.end());

    arr[0] = 1;

    for (int i = 1; i < arr.size(); i++) {
        arr[i] = min(arr[i], arr[i - 1] + 1);
    }

    return arr.back();
}

int main() {
    int n;
    cout << "Enter size of array: ";
    cin >> n;

    vector<int> arr(n);

    cout << "Enter array elements: ";
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    cout << "Maximum Element: "
         << maximumElementAfterDecrementingAndRearranging(arr)
         << endl;

    return 0;
}