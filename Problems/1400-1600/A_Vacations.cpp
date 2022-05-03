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
#define MULTICASE         \
    int t;                \
    cin >> t;             \
    while (t--)           \
    {                     \
        solution.solve(); \
    }
#define FASTIO                   \
    ios::sync_with_stdio(false); \
    cin.tie(nullptr);            \
    cout.tie(nullptr);
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
        vi a(n);
        fori(i, 0, n) cin >> a[i];

        grid(dp, n, 3);
        dp[0][0] = 0;
        dp[0][1] = (a[0] == 1 || a[0] == 3) ? 1 : 0;
        dp[0][2] = (a[0] == 2 || a[0] == 3) ? 1 : 0;
        fori(i, 1, n)
        {
            dp[i][0] = max({dp[i - 1][0], dp[i - 1][1], dp[i - 1][2]});
            dp[i][1] = (a[i] == 1 || a[i] == 3) ? max(dp[i - 1][0], dp[i - 1][2]) + 1 : 0;
            dp[i][2] = (a[i] == 2 || a[i] == 3) ? max(dp[i - 1][0], dp[i - 1][1]) + 1 : 0;
        }

        cout << n - max({dp[n - 1][0], dp[n - 1][1], dp[n - 1][2]}) << endl;
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