#include <iostream>
#include <vector>
using namespace std;

int largestAltitude(vector<int>& gain) {
    int ans = 0;
    int temp = 0;

    for (int i = 0; i < gain.size(); i++) {
        temp += gain[i];
        cout << "Current Altitude: " << temp << endl; // Optional
        ans = max(ans, temp);
    }

    return ans;
}

int main() {
    int n;

    cout << "Enter number of gains: ";
    cin >> n;

    vector<int> gain(n);

    cout << "Enter gain values: ";
    for (int i = 0; i < n; i++) {
        cin >> gain[i];
    }

    int result = largestAltitude(gain);

    cout << "Highest Altitude: " << result << endl;

    return 0;
}