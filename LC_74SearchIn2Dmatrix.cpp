#include<iostream>
using namespace std;

int BinarySearch(int arr[][3],int n,int m,int target){
    int s = 0;
    int e = m*n-1;
    int mid=s+(e-s)/2;
    cout << mid;

    while(s<=e){
        int element = arr[mid/m][mid%m];
        if(target==element){
            return 1;
        }
        else if(element < target){
            s = mid + 1;
        }
        else{
            e=mid-1;
        }
        mid=s+(e-s)/2;
    }
    return -1;

}

int main(){

    int arr[4][3] ={3,5,7,10,11,16,20,23,30,34,60};
    int target = 9;
    // cout<<"enter your target";
    // cin>> target;


    int k = BinarySearch(arr,4,3,target);

    if(k){
        cout << "element found";
    }
    else{
        cout << "not found";
    }

}