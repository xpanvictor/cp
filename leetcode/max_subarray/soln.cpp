
#include <bits/stdc++.h>
using namespace std;

// shorts
typedef long long ll;
typedef vector<int> vi;

int maxSubArray(vector<int> &nums)
{
    int best = nums[0], sum = 0, len = nums.size();
    for (int i = 0; i < len; i++)
    {
        sum = max(nums[i], sum + nums[i]);
        best = max(sum, best);
    }
    return best;
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(NULL);

    vi nums = {};
    int exp = 6;
    int res = maxSubArray(nums);
    printf("%d; true: %d\n", res, exp == res);
}
