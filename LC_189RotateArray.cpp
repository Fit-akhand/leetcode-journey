#include<iostream>
#include<vector>
using namespace std;

void rotate(int arr[],int n,int k){
        vector<int> brr(n);
         for(int i=0;i<n;i++){
        brr[(i+k)%n] = arr[i];
    }
    arr=brr;
}

void print(int arr[],int n){
    for(int i=0 ;i<n;i++){
        cout << arr[i] << " ";
    }
    cout << endl;
}

int main(){
    int arr[6]= {1,2,3,4,5,6};
    int rot=2;
    int size =6;

    rotate(arr,size,rot);

    print(arr,size);

}