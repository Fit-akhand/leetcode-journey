#include<iostream>
using namespace std ;
int main(){
    int n;
    int sum = 0;
    cout<<"enter a number : ";
    cin>> n ;
    // if you give binary input
    // while(n!=0){
    //     int a = n % 10;
    //     if(a==1){
    //         sum=sum+1;
    //     }
    //     n=n/10;
    // }

    //
    while(n!=0){
        if(n&1){
            sum=sum+1;
        }
        n= n>>1;
    }
    cout<< "Answer : " << sum ;
}