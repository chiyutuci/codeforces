#include <bits/stdc++.h>
using namespace std;

// type defination
#define ll long long
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef vector<int> vi;
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
#define fori(i, n) for (int i = 0; i < n; i++)
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
        vector<pii> s(n);
        fori(i, n)
        {
            cin >> s[i].first;
            cin >> s[i].second;
        }

        sort(all(s));
        int last = -1;
        fori(i, n)
        {
            if (last <= s[i].second)
                last = s[i].second;
            else
                last = s[i].first;
        }
        cout << last << endl;
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