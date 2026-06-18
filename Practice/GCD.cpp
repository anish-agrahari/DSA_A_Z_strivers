#include <bits/stdc++.h> 
using namespace std;

int findGcd(int x, int y)
{
    if(y == 0)
        return x;

    return findGcd(y, x % y);
}

int main()
{
    int x, y;
    cin >> x >> y;

    cout << findGcd(x, y);

    return 0;
}
