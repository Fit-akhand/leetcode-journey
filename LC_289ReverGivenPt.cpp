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
    }
    cout << endl;
}

int main(){
    // int orr[5] = {1,2,3,4,5};
    // int size1=5;
    int err[6] = {1,2,3,4,5,6};
    int size2=6;

    reverse(err,size2,2);
    // reverse(orr,size1);

    print(err,size2);
    // print(orr,size1);

}

