#include<iostream>
using namespace std;

void reverse(int arr[],int n, int m){
    int s=m+1;
    int e=n-1;
    while(s<=e){
        swap(arr[s],arr[e]);
        s++;
        e--;
    }
}

void print(int arr[],int n){
    for(int i=0 ;i<n;i++){
        cout << arr[i] << " ";