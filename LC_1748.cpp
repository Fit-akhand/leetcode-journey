#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int sumOfUnique(vector<int>& nums) {
        int freq[101] = {0};
        
        for(int num : nums){
            freq[num]++;
        }
        
        int sum = 0;
        for(int i = 0; i < 101; i++){
            if(freq[i] == 1){
                sum += i;
            }
        }
        return sum;
    }
};

int main() {
    vector<int> nums = {1,2,3,2};
    Solution obj;
    cout << obj.sumOfUnique(nums) << endl;
    return 0;
}
