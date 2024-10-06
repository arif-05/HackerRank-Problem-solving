//Bismillahir Rahmanir Rahim
#include<bits/stdc++.h>
#include<iostream>
using namespace std;

vector<int> insertion_sort(int n, vector<int> &arr){
    int temp = arr[n-1];
    int i = n-2;
    while(i >= 0 && arr[i]>temp){
        arr[i+1] = arr[i];
        i--;
        for(int j = 0; j<n; j++){
            cout<<arr[j]<<" ";
        }
        cout<<endl;
    }
    arr[i+1] = temp;
    
     for (int j = 0; j < n; j++) {
        cout << arr[j] << " ";
    }
    cout << endl;

}

int main(){
    int n;
    cin>>n;
    vector<int> arr(n);
    for(int i = 0; i<n; i++){
        cin>>arr[i];
    }

    insertion_sort(n,arr);
   



    return 0;
}