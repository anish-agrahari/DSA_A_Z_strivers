#include<bits/stdc++.h>
using namespace std;

// Function to merge two halves of the array
void merge(vector<int> &arr, int st, int mid, int end){
    vector<int> temp;  // Create temp arrays
    int i=st, j=mid+1;

    // Merge two sorted halves
    while (i<=mid && j<=end)
    {
        if(arr[i] <= arr[j]){
            temp.push_back(arr[i]);
            i++;
        } else {
            temp.push_back(arr[j]);
            j++;
        }
    }
    while (i<=mid) // Copy remaining elements from left half
    {
        temp.push_back(arr[i]);
        i++;
    }
    while (j<=end) // Copy remaining elements from right half
    {
        temp.push_back(arr[j]);
        j++;
    }

    // Copy sorted elements back to original array
    for(int i=0; i<temp.size(); i++){
        arr[st+i]=temp[i];
    }
}

void mergeSort(vector<int> &arr, int st, int end){
    if(st < end){
        int mid= st+(end-st)/2;

        mergeSort(arr, st, mid);
        mergeSort(arr, mid+1, end);

        merge(arr, st, mid, end);
    }
}

int main(){
    int n;
    cin >> n;
    vector<int> arr(n);
    for(int i=0; i<n; i++){
        cin >>  arr[i];
    }
    mergeSort (arr ,0, arr.size()-1);
    for(int i:arr){
        cout << i << " ";
    }
    cout << endl << "Array Sucessfully Sorted";
}