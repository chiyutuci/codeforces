#include <bits/stdc++.h>
using namespace std;

// type defination
#define int long long
typedef pair<int, int> pii;
typedef vector<int> vi;
typedef vector<string> vs;
typedef unordered_map<int, int> umii;

// macro defination
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
#define fori(i, n) for (int i = 0; i < n; i++)

// --------------------------------------------
// Write your program here
class Solution
{
public:
    void solve()
    {
        int n;
        cin >> n;
        umii rec;
        int mx = 0;
        fori(i, n)
        {
            int t;
            cin >> t;
            rec[t] += t;
            mx = max(mx, t);
        }

        int ans = 0;
        vi dp(mx + 1);
        dp[0] = 0;
        dp[1] = rec[1];
        for (int i = 2; i <= mx; i++)
        {
            dp[i] = max(dp[i - 1], dp[i - 2] + rec[i]);
            ans = max(ans, dp[i]);
        }

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