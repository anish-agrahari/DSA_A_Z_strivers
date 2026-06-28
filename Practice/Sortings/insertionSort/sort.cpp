#include<bits/stdc++.h>
using namespace std;

void insertionSort(int arr[], int n){
    for(int i=0; i<=n-1; i++){
        int current= i;
        while(current>0 && arr[current-1]> arr[current]){
        int temp=arr[current-1];
        arr[current-1]=arr[current];
        arr[current]=temp;
        current--;44
        }
    }
}

int main(){
    int n;
    cin >> n;
    int arr[n];
    for(int i=0; i<n; i++){
        cin >>  arr[i];
    }

    insertionSort (arr , n);
    for(int i=0; i<n; i++){
        cout << arr[i] << " ";
    }
    cout << endl << "Array Sucessfully Sorted";
}