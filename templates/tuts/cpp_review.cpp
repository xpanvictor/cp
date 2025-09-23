#include <bits/stdc++.h>
using namespace std;

// macros
#define F first
#define S second
#define PB push_back
#define MP make_pair
#define REP(i, a, b) for (int i = a; i <= b; i++)

typedef long long ll;
typedef vector<int> vi;
typedef pair<int, int> pi;
typedef vector<pi> vpi;

// Comparison between fp numbers due to precision issues
bool double_equal(double a, double b)
{
    return abs(a - b) < 1e-9;
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(NULL);

    REP(i, 0, 5)
    {
        printf("%d\n", i);
    }

    int a, b;
    string x;
    scanf("%d %d", &a, &b);
    getline(cin, x);
    // string story;
    // while (cin >> story)
    // {
    // }
    cout << a << " " << b << " " << x << "\n";

    // file
    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
    // long long c = a * b; // wrong
    ll c = (ll)a * b;
    cout << "Result: " << c << "\n";

    double cm = 0.00009;
    printf("%.9f\n", cm);

    // vectors
    vpi v;
    v.PB(MP(1, 2));
    v.PB(MP(3, 4));
    int sum = v[0].F + v[1].S;
    printf("Res: %d\n", sum);
}