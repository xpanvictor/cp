#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(NULL);

    int x;
    cin >> x;

    while (true)
    {
        cout << x;
        if (x == 1)
            break;
        cout << " ";
        if (x % 2 == 1)
            x = x * 3 + 1;
        else
            x /= 2;
    }
    cout << "\n";
    return 0;
}