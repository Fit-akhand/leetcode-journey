#include<iostream>
using namespace std;

int isprime(int n){
    for(int i=2;i<n;i++){
        if(n%i==0){
            return 0;
        }
    }
    return n;

}

int main(){
    int n;
    cout << "enter a number to check prime";
    cin >> n;
    int count=0;
    for(int i=2;i<n;i++){
        int k = isprime(i);
        if(k){
           cout << k << endl;
        }
    }
    
}