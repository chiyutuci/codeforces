#include <bits/stdc++.h>
using namespace std;

// type defination
#define MAX LONG_LONG_MAX
#define MIN LONG_LONG_MIN
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
        int n, a, b;
        cin >> n >> a >> b;
        vi nums(n + 1);
        nums[0] = 0;
        fori(i, n) cin >> nums[i + 1];
        vi pre(n + 1);
        int sum = 0;
        fori(i, n + 1)
        {
            sum += nums[i];
            pre[i] = sum;
        }

        int mn = LONG_LONG_MAX;
        fori(i, n)
        {
            int cost = a * nums[i];
            cost += b * (pre[n] - pre[i] - (n - i - 1) * nums[i]);
            mn = min(mn, cost);
        }

        cout << mn << endl;
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