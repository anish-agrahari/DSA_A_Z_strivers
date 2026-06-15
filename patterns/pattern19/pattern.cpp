#include<bits/stdc++.h>
using namespace std;

int main(){
    int n;
    cin >> n;

    int iniS = 0;

    for(int i=0; i<n; i++){

        for(int j=1; j<=n-i; j++){
            cout << "*";
        }
        for(int j=0; j<iniS; j++){
            cout << " ";
        }
        for(int j=1; j<=n-i; j++){
            cout << "*";
        }
        iniS += 2;
        cout << endl;
    }
    for(int i=0; i<n; i++){
        for(int j=1; j<=i+1; j++){
            cout << "*";
        }
        for(int j=0; j<iniS-2; j++){
            cout << " ";
        }
        for(int j=1; j<=i+1; j++){
            cout << "*";
        }
        iniS -= 2;
        cout << endl;
    }
    return 0;
}