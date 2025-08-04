#include<iostream>
using namespace std;
int square(int n){
    int s=0;
    int e=n;
    int mid = s+(e-s)/2;
    long long int ans =-1;
        while(s<=e){
        long long int sq = mid*mid;
        if(sq==n){
            return mid;
        }
        else if(sq > n){
            e=mid-1;
            
        }
        else {
            s=mid+1;
            ans=mid;
        }
        mid = s+(e-s)/2;
    }
    return ans;
}
double preseasion(int x,int n){
    double a =x;
    double sq= a*a;
    while(sq<n){
    if(sq == n){
        return a;
    }
    else{
        a+=0.01;
    }
    sq= a*a;
    }
    return a;
}
int main(){
    int n=40;
    int ans = square(n);
    double x = preseasion(ans,n); 
    cout <<"square root is : " << ans << endl; ;
    cout <<"pre square root is : " << x ;
}