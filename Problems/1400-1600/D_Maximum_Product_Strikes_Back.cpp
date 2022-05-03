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
        vi nums(n);
        fori(i, n) cin >> nums[i];

        int mn = 0, al = 0, ar = 0;
        int l = -1;
        while (l < n - 1)
        {
            int m = 0, nml = 0, rml = 0;
            int la = l, ra = l;
            int ln = -1, rn = -1;
            bool neg = false;
            if (l == -1 || nums[l] == 0)
            {
                while (l < n - 1 && nums[++l] != 0)
                {
                    if (nums[l] < 0)
                    {
                        if (ln == -1)
                        {
                            ln = l;
                            nml = abs(nums[l]) == 2 ? m + 1 : m;
                        }
                        rn = l - 1;
                        rml = m;
                        neg = !neg;
                    }
                    m += abs(nums[l]) == 2 ? 1 : 0;
                }
                ra = nums[l] == 0 ? l - 1 : l;
                if (neg)
                {
                    if (m - nml > rml)
                    {
                        la = ln;
                        m -= nml;
                    }
                    else
                    {
                        ra = rn;
                        m = rml;
                    }
                }
                if (m > mn)
                {
                    mn = m;
                    al = la;
                    ar = ra;
                }
            }
        }
        cout << al + 1 << " " << n - ar - 1 << endl;
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