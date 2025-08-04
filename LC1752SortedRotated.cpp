#include<iostream>
#include<vector>
using namespace std;
bool check(vector<int> arr){
    int n=arr.size();
    int count=0;
    for(int i=0;i<n-1;i++){
        if(arr[i]>arr[i+1]){
            count++;
        }
    }
    if(arr[0]<arr[n-1]){
        count++;
    }
    return count<=1;
}
int main(){
    vector<int> arr ={5,6,1,2,3};

    cout <<"final ans :- " << check(arr);
}

////  MY CODE

// #include<iostream>
// #include<vector>
// using namespace std;

//  bool check(vector<int>& nums) {
//     int i=0;
//     int j=0;
//     int n =nums.size();
//     while(i<n-1 && j<=2){
//         if(nums[i]==nums[i+1] && nums[i]==nums[n-1]){
//         return true;
//     }
//     else{
//         if(nums[i]<nums[i+1]){
//             i++;
//         }
//         else if(nums[i]==nums[i+1]){ 
//             i++;
//         }
//          else if(nums[0]<nums[n-1]){
//             j++;
//         }
//         else{
//             i++;
//             j++;
//         }
//     }
//     }
//     if(j>=2){
//        return false;
//     }
//     else {
//         return true;
//     }
//  }

// int main(){
//     vector<int> arr = {5,5,6,6,6,9,12};


//     cout << check(arr) ;

// }