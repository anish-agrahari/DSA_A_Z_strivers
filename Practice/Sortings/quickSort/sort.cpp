#include<bits/stdc++.h>
using namespace std;

int partition(vector<int> &arr, int st, int end){
    int idx = st-1, pivot = arr[end];
    for(int j=st; j<end; j++){
        if(arr[j] <= pivot){
        idx++;
        swap(arr[j],arr[idx]);
        }
    }
    idx++;
    swap(arr[end], arr[idx]);
    return idx;
}

void quickSort(vector<int> &arr, int st, int end){
    if(st<end){
        int pivotIndex=partition (arr, st, end);
        quickSort(arr,st,pivotIndex-1);
        quickSort(arr,pivotIndex+1,end);
    }
}

int main(){
    int n;
    cin >> n;
    vector<int> arr(n);
    for(int i=0; i<n; i++){
        cin >>  arr[i];
    }
    quickSort (arr ,0, arr.size()-1);
    for(int i:arr){
        cout << i << " ";
    }
    cout << endl << "Array Sucessfully Sorted";
}