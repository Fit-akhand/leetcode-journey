#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool isVowel(char ch) {
        ch = tolower(ch); // convert to lowercase for safety
        return (ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u');
    }

    int maxVowels(string s, int k) {
        int count = 0;
        deque<int> dq;

        // First window
        for (int i = 0; i < k; i++) {
            if (isVowel(s[i])) {
                dq.push_back(i);
            }
        }
        count = dq.size();

        // Sliding window
        for (int i = k; i < s.size(); i++) {

            // Remove index if it moves out of window
            if (!dq.empty() && dq.front() < i - k + 1) {
                dq.pop_front();
            }

            // Add current character if vowel
            if (isVowel(s[i])) {
                dq.push_back(i);
            }

            // Update max vowel count
            count = max(count, (int)dq.size());
        }

        return count;
    }
};

int main() {
    Solution obj;

    string s;
    int k;

    cout << "Enter string: ";
    cin >> s;
    cout << "Enter k: ";
    cin >> k;

    cout << "Maximum number of vowels in any substring of size k: "
         << obj.maxVowels(s, k) << endl;

    return 0;
}