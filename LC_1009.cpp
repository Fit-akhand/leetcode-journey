#include<iostream>
#include<math.h>
using namespace std;
int main(){
    int n ;
    cout << "enter a decimal number : " ;
    cin >> n ;

    int m=n;
    int mask =0;
    int ans;
    
    while(m!=0){
        mask=(mask<<1) | 1;
        m = m >>1 ;
    }
    // edge case 
    if(n==0){
        ans =1;
    }
    else ans =(~n)& mask;
    cout <<"answer : " << ans;

}