#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(NULL);

    ll x;
    cin >> x;

    for (; cout << x << (x > 1 ? " " : "\n"), x > 1;)
        x = (x % 2) ? 3 * x + 1 : x / 2;
}