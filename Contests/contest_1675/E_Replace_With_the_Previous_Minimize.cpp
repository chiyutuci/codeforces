#include <bits/stdc++.h>
using namespace std;

// type defination
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef vector<int> vi;
typedef vector<ll> vl;
typedef vector<vector<int>> vvi;
typedef vector<vector<ll>> vvl;
typedef vector<string> vs;
typedef unordered_map<int, int> umii;

// macro defination
#define SINGLECASE solution.solve();
#define MULTICASE \
  int t;          \
  cin >> t;       \
  while (t--)     \
    solution.solve();
#define FASTIO                 \
  ios::sync_with_stdio(false); \
  cin.tie(nullptr);
#define fori(i, l, r) for (int i = l; i < r; i++)
#define grid(x, m, n) vvi x(m, vi(n));
#define gridl(x, m, n) vvl x(m, vl(n));
#define all(x) x.begin(), x.end()

// constant defination
const int MOD = 1000000007;
const int N = 100005;

// --------------------------------------------
// Write your program here
class Solution
{
public:
  void solve()
  {
    int n, k;
    cin >> n >> k;
    string s;
    cin >> s;

    int mx = 0;
    fori(i, 0, n)
    {
      if (s[i] - 'a' > k)
      {
        char c = s[i] - (k - mx);
        char m = s[i];
        fori(j, 0, n)
        {
          if (c <= s[j] && s[j] <= m)
            s[j] = c;
        }
        break;
      }
      mx = max(mx, s[i] - 'a');
    }

    fori(i, 0, n)
    {
      if (s[i] <= 'a' + mx)
        s[i] = 'a';
    }
    cout << s << endl;
  }

private:
};

// --------------------------------------------
// By default SINGLECASE
int main()
{
  FASTIO;

  Solution solution;

  MULTICASE;

  return 0;
}