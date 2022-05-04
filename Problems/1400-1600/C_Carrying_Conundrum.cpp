#include <bits/stdc++.h>
using namespace std;

// type defination
#define ll long long
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef vector<int> vi;
typedef vector<ll> vl;
typedef vector<vector<int>> vvi;
typedef vector<vector<ll>> vvl;
typedef vector<string> vs;
typedef unordered_map<int, int> umii;

// macro defination
const int MOD = 1000000007;
#define SINGLECASE solution.solve();
#define MULTICASE                                                              \
  int t;                                                                       \
  cin >> t;                                                                    \
  while (t--)                                                                  \
    solution.solve();
#define FASTIO                                                                 \
  ios::sync_with_stdio(false);                                                 \
  cin.tie(nullptr);
#define fori(i, l, r) for (int i = l; i < r; i++)
#define read(a)                                                                \
  for (int &x : a)                                                             \
    cin >> x;
#define grid(x, m, n) vvi x(m, vi(n));
#define gridl(x, m, n) vvl x(m, vl(n));
#define all(x) x.begin(), x.end()

// --------------------------------------------
// Write your program here
const int N = 100005;
class Solution {
public:
  void solve() {
    string s;
    cin >> s;

    string s1, s2;
    fori(i, 0, s.size()) {
      if (i % 2 == 0)
        s1.push_back(s[i]);
      else
        s2.push_back(s[i]);
    }
    int a1 = s1.size() > 0 ? stoi(s1) : 0;
    int a2 = s2.size() > 0 ? stoi(s2) : 0;
    cout << 1LL * (a1 + 1) * (a2 + 1) - 2 << endl;
  }

private:
};

// --------------------------------------------
// By default SINGLECASE
signed main() {
  FASTIO;

  Solution solution;
  // SINGLECASE;
  MULTICASE;

  return 0;
}