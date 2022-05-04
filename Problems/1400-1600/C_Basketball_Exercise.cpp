#include <bits/stdc++.h>
using namespace std;

// type defination
#define ll long long
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef vector<int> vi;
typedef vector<ll> vl;
typedef vector<string> vs;
typedef vector<vector<int>> vvi;
typedef vector<vector<ll>> vvl;
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
#define gridl(x, m, n) vvl x(m, vl(n));
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
        vi r1(n), r2(n);
        fori(i, 0, n) cin >> r1[i];
        fori(i, 0, n) cin >> r2[i];

        gridl(dp, n, 3);
        dp[0][0] = 0;
        dp[0][1] = r1[0];
        dp[0][2] = r2[0];

        fori(i, 1, n)
        {
            dp[i][0] = max({dp[i - 1][0], dp[i - 1][1], dp[i - 1][2]});
            dp[i][1] = max(dp[i - 1][0], dp[i - 1][2]) + r1[i];
            dp[i][2] = max(dp[i - 1][0], dp[i - 1][1]) + r2[i];
        }

        cout << max({dp[n - 1][0], dp[n - 1][1], dp[n - 1][2]}) << endl;
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