#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

ll gcd(ll a, ll b)
{
    if (b == 0)
        return a;

    return gcd(b, a % b);
}

ll lcm(ll a, ll b)
{
    return (ll)(a * b) / gcd(a, b);
}

double find_median(vector<int> &arr)
{
    if (arr.empty())
        return 0.0;
    sort(arr.begin(), arr.end());
    int s = arr.size();
    if (s % 2 == 0)
        return (arr[s / 2 - 1] + arr[s / 2]) / 2.0;
    else
        return arr[s / 2];
}

double find_median_counting_sort(vector<int> &arr, int d)
{
    // find cummulative sum; take note of even median too
    int cum = 0;
    int m1 = -1, m2 = -1;
    int pos1 = (d + 1) / 2;
    int pos2 = (d % 2 == 0) ? (d / 2 + 1) : pos1;
    for (int i = 0; i < arr.size(); ++i)
    {
        cum += arr[i];
        if (m1 == -1 && cum >= pos1)
        {
            m1 = i;
        };
        if (m2 == -1 && cum >= pos2)
        {
            m2 = i;
            break;
        }
    }
    return (m1 + m2) / 2.0;
}
