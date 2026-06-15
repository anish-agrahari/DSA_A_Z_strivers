#include<bits/stdc++.h>
using namespace std;

int main(){
    int n;
    cin >> n;
    int num = 1;
    for(int i=n;i>=1;i--){
        for(char ch = 'A';ch<'A'+i;ch++){
            cout << ch << " ";
        }
cout << endl;
}
return 0;
}