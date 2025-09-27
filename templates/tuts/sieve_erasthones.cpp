#include <bits/stdc++.h>
using namespace std;

typedef vector<int> vi;
typedef vector<bool> vb;

vi sieve(int n)
{
    vb primes(n + 1, true);
    vi soln;
    primes[0] = primes[1] = false;
    for (int p = 2; p * p <= n; p++)
    {
        if (primes[p])
        {
            for (int i = p * p; i <= n; i += p)
            {
                primes[i] = false;
            }
        }
    }
    for (int i = 2; i <= n; i++)
    {
        if (primes[i])
            soln.push_back(i);
    }
    return soln;
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int test = 11;
    vi exp{2, 3, 5, 7, 11};
    vi res = sieve(test);
    for (int i = 0; i < res.size(); i++)
    {
        printf("exp: %d, got: %d\n", exp[i], res[i]);
    }
}
