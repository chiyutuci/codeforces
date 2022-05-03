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
int n, m;
int ans;
int cats[N];
vi tree[N];

void dfs(int v, int pr, int k)
{
    if (cats[v])
        k++;
    else
        k = 0;
    if (k == m + 1)
        return;

    bool leaf = true;
    for (auto to : tree[v])
    {
        if (to != pr)
        {
            leaf = false;
            dfs(to, v, k);
        }
    }
    if (leaf)
        ++ans;
}

void solve()
{
    cin >> n >> m;
    fori(i, n) cin >> cats[i];
    fori(_, n - 1)
    {
        int x, y;
        cin >> x >> y;
        x--, y--;
        tree[x].push_back(y);
        tree[y].push_back(x);
    }
    dfs(0, -1, 0);
    cout << ans << endl;
}

// --------------------------------------------
// By default SINGLECASE
int main()
{
    FASTIO;

    SINGLECASE;
    // MULTICASE;

    return 0;
}