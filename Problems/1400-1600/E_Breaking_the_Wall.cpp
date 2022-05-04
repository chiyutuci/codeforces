#include <bits/stdc++.h>
using namespace std;

// type defination
#define ll long long
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef vector<int> vi;
typedef vector<vector<int>> vvi;
typedef vector<string> vs;
typedef unordered_map<int, int> umii;

// macro defination
const int N = 100500;
#define SINGLECASE solution.solve();
#define MULTICASE \
    int t;        \
    cin >> t;     \
    while (t--)   \
        solution.solve();
#define FASTIO                   \
    ios::sync_with_stdio(false); \
    cin.tie(nullptr);
#define fori(i, l, r) for (int i = l; i < r; i++)
#define grid(x, m, n) vvi x(m, vi(n));
#define all(x) x.begin(), x.end()

// --------------------------------------------
// Write your program here
class Solution
{
public:
    void solve()
    {
        int n;
        cin >> n;
        vi nums(n);
        fori(i, 0, n) cin >> nums[i];

        int ans = INT_MAX;

        fori(i, 0, n - 1)
        {
            ans = min(ans, max({(nums[i] + 1) / 2, (nums[i + 1] + 1) / 2, (nums[i] + nums[i + 1] + 2) / 3}));
        }
        fori(i, 0, n - 2)
        {
            ans = min(ans, (nums[i] + nums[i + 2] + 1) / 2);
        }

        sort(all(nums));
        ans = min(ans, (nums[0] + 1) / 2 + (nums[1] + 1) / 2);
        cout << ans << endl;
    }

private:
};

// --------------------------------------------
// By default SINGLECASE
signed main()
{
    FASTIO;

    Solution solution;
    SINGLECASE;
    // MULTICASE;

    return 0;
}