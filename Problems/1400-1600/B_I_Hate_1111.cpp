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
        int x;
        cin >> x;

        fori(i, 0, 12)
        {
            if (x % 11 == 0)
            {
                cout << "YES" << endl;
                return;
            }
            x -= 111;
            if (x < 0)
                break;
        }

        cout << "NO" << endl;
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