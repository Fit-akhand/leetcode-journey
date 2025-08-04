#include<iostream>
using namespace std;

void sortZero(int arr[],int size){
    int i=0;
    for(int j=0;j<size;j++){
        if(arr[j]!=0){
            swap(arr[j],arr[i]);
            i++;
        }
    }
}
void print(int a3[] ,int n ){
    for(int i=0;i<n;i++){
        cout<< a3[i] << " " ;
    } 
}

int main(){
    int arr[6] = {0,1,0,0,3,12};
    int size =6;
    sortZero(arr,size);
    print(arr,size);
}