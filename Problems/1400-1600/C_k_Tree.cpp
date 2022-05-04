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
const int MOD = 1000000007;
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
        int n, k, d;
        cin >> n >> k >> d;

        gridl(dp, n + 1, d + 1);
        dp[1][1] = 1;
        dp[0][1] = 1;
        fori(i, 2, n + 1)
        {
            fori(j, 1, d + 1)
            {
                if (i < j)
                    break;
                if (i == j)
                {
                    dp[i][j] = 1;
                    break;
                }
                for (int s = j; s <= k && s <= i; s++)
                {
                    dp[i][j] += dp[i - s][1];
                    dp[i][j] = dp[i][j] % MOD;
                }
                fori(s, 1, j)
                {
                    dp[i][j] += dp[i - s][j];
                    dp[i][j] = dp[i][j] % MOD;
                }
            }
        }

        cout << dp[n][d] << endl;
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