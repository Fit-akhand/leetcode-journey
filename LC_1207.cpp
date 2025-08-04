#include<iostream>
#include <unordered_map>

using namespace std;
bool unique(int arr[], int size){
    unordered_map<int, int> freq;  
    for (int num : arr) {
        freq[num]++; 
    }
    int ans=0;
        for(int i=0 ; i<size;i++){
            ans = ans^arr[i];
        }
        if(ans){
            return true;
        }
        else return false;

}
int main(){
    int arr[9] = {1 ,3 ,1 ,3 ,6 ,6 ,7 ,10 ,7};
    bool a = unique(arr,9);

    cout << "ans is : " << a;
}