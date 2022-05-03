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
    int casesNum;         \
    cin >> casesNum;      \
    while (casesNum--)    \
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

        vi nums(n + 1);
        nums[0] = 1;
        fori(i, n - 1)
        {
            int t;
            cin >> t;
            nums[t]++;
        }

        sort(nums.rbegin(), nums.rend());

        int l = 0, r = n, ans = n;
        while (l <= r)
        {
            int m = l + (r - l) / 2;
            if (check(nums, m))
            {
                ans = m;
                r = m - 1;
            }
            else
                l = m + 1;
        }

        cout << ans << endl;
    }

private:
    bool check(vi &nums, int x)
    {
        int n = nums.size();
        vi b(n);
        int now = 0;
        fori(i, x)
        {
            if (nums[i])
            {
                b[i] = x - now;
                now++;
            }
        }
        int s = 0;
        fori(i, n)
        {
            if (nums[i] && nums[i] > b[i])
                s += nums[i] - b[i];
        }
        if (s + now > x)
            return false;
        return true;
    }
};
// --------------------------------------------
signed main()
{
    FASTIO;

    Solution solution;
    // SINGLECASE;
    MULTICASE;

    return 0;
}