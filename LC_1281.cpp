#include<iostream>
using namespace std;
int main(){
    int n;
    cout<<"enter a number : ";
    cin>> n ;
    int sum = 0 ;
    int product = 1 ;
    while(n!=0){
        int a = n % 10 ;
        sum = sum + a ;
        product = product * a ;
        n=n/10;
    }
    cout << product - sum ;
}