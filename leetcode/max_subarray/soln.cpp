
#include <bits/stdc++.h>
using namespace std;

// shorts
typedef long long ll;
typedef vector<int> vi;

int maxSubArray(const vector<int> &nums)
{
    int best = nums[0], sum = 0, len = nums.size();
    for (auto x : nums)
    {
        sum = max(x, x + sum);
        best = max(best, sum);
    }
    return best;
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(NULL);

    vi nums = {1, 2, -3, 2, 5};
    int exp = 7;
    int res = maxSubArray(nums);
    printf("%d; true: %d\n", res, exp == res);
}
