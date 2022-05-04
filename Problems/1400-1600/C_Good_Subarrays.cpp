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
        string s;
        cin >> s;

        vi pre(n + 1);
        fori(i, 1, n + 1) pre[i] = pre[i - 1] + s[i - 1] - '0';

        umii dis;
        fori(i, 1, n + 2) dis[pre[i - 1] - i]++;

        ll ans = 0;
        for (auto &x : dis)
            ans += 1LL * x.second * (x.second - 1) / 2;

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
    // SINGLECASE;
    MULTICASE;

    return 0;
}