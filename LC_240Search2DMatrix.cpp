#include<iostream>
#include<vector>
using namespace std;

bool findInMatrix(int x, vector<vector<int>> &arr)
{
    int row = arr.size();
    int col = arr[0].size();
    
    int rowindex=0;
    int colindex = col-1;

    while(rowindex < row && colindex >=0){
        int element = arr[rowindex][colindex];
        if(x==element){
            return 1;
        }
        if(x > element){
            rowindex++;
        }
        else{
            colindex--;
        }
    }
    return 0;

}

int main(){

    vector<vector<int>> arr = {
        {1, 2, 4, 5},
        {3, 4, 9, 16},
        {7, 10, 14, 29}
    };
    int target =9;
    int k = findInMatrix(target,arr);

    if(k){
        cout << "present " ;
    }
    else{
        cout << "absent" ; 
    }

}