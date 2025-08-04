#include<iostream>
using namespace std;

int Peak(int arr[],int size){
    int s=0;
    int e=size-1;
    int mid = s+(e-s)/2;
    while (s<e){
    if(arr[mid] < arr[mid+1]){
        s = mid+1;
    }
    else {
        e=mid;
    }
    mid=s+(e-s)/2;
}
return arr[mid];
}

int main(){
    int arr[4] ={3,4,5,1};
    int size=4;
    int ans = Peak(arr,size);
    cout<< "max number is: " << ans ;
}