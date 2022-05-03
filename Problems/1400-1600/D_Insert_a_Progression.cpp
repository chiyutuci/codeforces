#include <bits/stdc++.h>
using namespace std;

// type defination
typedef long long ll;
#define pii pair<int, int>
#define pll pair<ll, ll>

// macro defination
#define SINGLECASE solve();
#define MULTICASE \
    int t;        \
    cin >> t;     \
    while (t--)   \
    {             \
        solve();  \
    }
#define FASTIO                   \
    ios::sync_with_stdio(false); \
    cin.tie(nullptr);            \
    cout.tie(nullptr);
#define fori(i, n) for (int i = 0; i < n; i++)

// --------------------------------------------
// Write your program here
void solve()
{
    int n, x;
    cin >> n >> x;
    vector<int> nums(n);
    fori(i, n) cin >> nums[i];

    ll ans = 1e18;
    ll cur = 0;
    fori(i, n - 1) cur += abs(nums[i + 1] - nums[i]);

    fori(_, 2)
    {
        ll mn = nums[0] - 1;
        ans = min(ans, cur + abs(nums[0] - x) + x - 1);
        fori(i, n - 1)
        {
            ans = min(ans, cur + mn - abs(nums[i] - nums[i + 1]) + abs(nums[i] - x) + abs(nums[i + 1] - x));
            ans = min(ans, cur - abs(nums[i] - nums[i + 1]) + abs(nums[i] - x) + abs(nums[i + 1] - 1) + (x - 1));
            mn = min(mn, 0ll - abs(nums[i] - nums[i + 1]) + abs(nums[i] - 1) + abs(nums[i + 1] - 1));
        }
        ans = min(ans, cur + mn + abs(nums.back() - x));
        reverse(nums.begin(), nums.end());
    }

    cout << ans << endl;
}

// --------------------------------------------
// By default SINGLECASE
int main()
{
    FASTIO;

    // SINGLECASE;
    MULTICASE;

    return 0;
}