#include <bits/stdc++.h>
using namespace std;

// type defination
#define ll long long
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef vector<int> vi;
typedef vector<ll> vl;
typedef vector<vector<int>> vvi;
typedef vector<vector<ll>> vvl;
typedef vector<string> vs;
typedef unordered_map<int, int> umii;

// macro defination
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
const int N = 100500;

class Solution
{
public:
    void solve()
    {
        int n;
        cin >> n;
        vi a(n + 1);
        fori(i, 1, n + 1) cin >> a[i];

        gridl(dp, n + 1, 2);
        dp[1][0] = 0;
        dp[1][1] = 1;

        fori(i, 2, n + 1)
        {
            dp[i][0] = max(dp[i - 1][0], dp[i - 1][1]);
            dp[i][1] = a[1] < a[i] ? 2 : 1;
            for (int j = 2; j < i && j * j <= i; j++)
            {
                if (i % j == 0)
                {
                    if (a[j] < a[i])
                        dp[i][1] = max(dp[i][1], dp[j][1] + 1);
                    int p = i / j;
                    if (a[p] < a[i])
                        dp[i][1] = max(dp[i][1], dp[p][1] + 1);
                }
            }
        }

        cout << max(dp[n][0], dp[n][1]) << endl;
    }

private:
};

// --------------------------------------------
// By default SINGLECASE
signed main()
{
    FASTIO;

    Solution solution;
    // SINGLECASE;
    MULTICASE;

    return 0;
}