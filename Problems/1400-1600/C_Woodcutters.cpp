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
        vector<pii> trees(n);
        fori(i, 0, n)
        {
            cin >> trees[i].first;
            cin >> trees[i].second;
        }

        grid(dp, n, 3);
        dp[0][0] = 0;
        dp[0][1] = 1;
        if (0 == n - 1 || trees[0].first + trees[0].second < trees[1].first)
            dp[0][2] = 1;

        fori(i, 1, n)
        {
            dp[i][0] = max({dp[i - 1][0], dp[i - 1][1], dp[i - 1][2]});

            if (trees[i].first - trees[i].second > trees[i - 1].first)
                dp[i][1] = max(dp[i - 1][0], dp[i - 1][1]) + 1;
            if (trees[i].first - trees[i].second > trees[i - 1].first + trees[i - 1].second)
                dp[i][1] = max(dp[i][1], dp[i - 1][2] + 1);

            if (i == n - 1 || trees[i].first + trees[i].second < trees[i + 1].first)
                dp[i][2] = dp[i][0] + 1;
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