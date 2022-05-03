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
        string s;
        cin >> s;
        int n = s.size();
        fori(i, n)
        {
            if (s[i] == '0' || s[i] == '8')
            {
                cout << "YES\n"
                     << s[i] << endl;
                return;
            }
        }
        for (int i = n - 1; i >= 0; i--)
        {
            int a = s[i] - '0';
            for (int j = i - 1; j >= 0; j--)
            {
                int b = 2 * (s[j] - '0');
                if (b != 0 && (b + a) % 8 == 0)
                {
                    string res;
                    cout << "YES\n"
                         << s[j] << s[i] << endl;
                    return;
                }
                for (int k = j - 1; k >= 0; k--)
                {
                    int c = 4 * (s[k] - '0');
                    if (c != 0 && (c + b + a) % 8 == 0)
                    {
                        cout << "YES\n"
                             << s[k] << s[j] << s[i] << endl;
                        return;
                    }
                }
            }
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
    SINGLECASE;
    // MULTICASE;

    return 0;
}