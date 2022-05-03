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
    int n;
    cin >> n;

    vector<string> grid(n);

    fori(i, n) cin >> grid[i];

    int sum = 0;
    int ma = 0;
    fori(i, n)
    {
        int cnt = 0;
        fori(j, n)
        {
            cnt += grid[(j + i) % n][j] - '0';
        }
        ma = max(ma, cnt);
        sum += cnt;
    }

    cout << sum - ma + n - ma << endl;

    return;
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