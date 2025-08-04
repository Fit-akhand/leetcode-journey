#include<iostream>
#include<math.h>
#include<climits>
using namespace std;
int main(){
    int x ;
    cout << "Enter a number to reverse : ";
    cin >> x ;
    int ans = 0;
    while(x!=0){
        int a = x % 10;
        if((x > INT_MAX/10 || x< (INT_MIN/10))){
            ans =0 ;
            break;
        }
        ans = (ans * 10) +a ;
        x = x / 10;
    }
    cout << "Reverse number is : " << ans ;
}