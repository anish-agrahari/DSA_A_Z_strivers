#include <iostream>
using namespace std;

int main() {
    int n;
    cin >> n ;
    for(int i=0; i<n; i++) {
        for(int j=0;j<n-i-1;j++){
            cout << " " ;
        }
        for(int k=0;k<2*i+1;k++){
            cout << "*" ;
        }
        for(int l=0;l<n-i-1;l++){
            cout << " " ;
        }
        cout << endl;
    }

    for(int i = n; i >= 1; i--) {

        for(int j = 1; j <= n - i; j++)
            cout << " ";
 
        for(int j = 1; j <= 2 * i -1; j++)
            cout << "*";

        cout << endl;
    }
}
