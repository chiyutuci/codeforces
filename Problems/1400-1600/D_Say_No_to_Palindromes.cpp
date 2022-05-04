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
  while (t--) solution.solve();
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
class Solution {
 public:
  void solve() {
    int n, m;
    cin >> n >> m;
    string s;
    cin >> s;

    string p = "abc";
    grid(pre, 6, n + 1);

    int cur = 0;
    do {
      fori(i, 0, n) { pre[cur][i + 1] = pre[cur][i] + (s[i] != p[i % 3]); }
      cur++;
    } while (next_permutation(all(p)));

    while (m--) {
      int l, r;
      cin >> l >> r;
      int ans = n;
      fori(i, 0, 6) { ans = min(ans, pre[i][r] - pre[i][l - 1]); }
      cout << ans << endl;
    }
  }

 private:
};

// --------------------------------------------
// By default SINGLECASE
int main() {
  FASTIO;

  Solution solution;
  SINGLECASE;
  // MULTICASE;

  return 0;
}