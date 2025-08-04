#include<iostream>
#include<math.h>
using namespace std;
int main(){
    int n;
    cout << "enter a decimal number : ";
    cin >> n;
    int k=0;
    if(n==0){
        return false;
    }
    else if(n<0){
        return false;
    }
    else{
        int i=0;
        while (i!=715827882)
        {
            int a =pow(3, i);
            i++;
            if(n==a){
                k=1;
            }    
            i++;
        }
    }

    if(k==1){
        cout<< "n is divisible by 3" ;
    } else cout << " nis not divisible by 3" ;
    
}