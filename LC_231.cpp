#include <iostream>
#include <math.h>
using namespace std;
int main()
{
    int n;
    cout << "enter a decimal number : ";
    cin >> n;

    // int check = 0;
    // if (n == 1)
    // {
    //     int a =pow(2, 0);
    //     int k = n % a;
    //     if (k == 0)
    //     {
    //         cout << "true";
    //         check = 1;
    //     }
    // }
    // int i = 1;
    // while (n != 0)
    // {
    //     int k;
    //     int a =pow(2, i);
    //     k = n % a;
    //     if (k == 0)
    //     {
    //         cout << "true";
    //         check = 1;
    //         break;
    //     }
    //     i++;
    // }
    // if (check == 0)
    // {
    //     cout << "false";
    // }

    for(int i=0 ; i<=30 ;i++){
        int ans =pow(2,i);
        if(ans==n){
            cout << 'true';
        }
    }
    cout << 'false';
}