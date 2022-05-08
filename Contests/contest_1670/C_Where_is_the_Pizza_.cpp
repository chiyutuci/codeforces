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
    int n;
    cin >> n;
    vi a(n);
    vi b(n);
    vi c(n);
    vi d(n + 1);
    vi pos(n + 1);
    fori(i, 0, n) {
      cin >> a[i];
      pos[a[i]] = i;
    }
    fori(i, 0, n) { cin >> b[i]; }

    fori(i, 0, n) {
      int x;
      cin >> x;
      c[i] = x;
    }

    ll ans = 1;
    fori(i, 0, n) {
      if (d[a[i]] == 0) {
        int head = a[i];
        int prev = a[i];
        d[prev] = 1;
        int next = b[i];
        while (next != prev && next != head) {
          int p = pos[next];
          prev = a[p];
          d[prev] = 1;
          next = b[p];
          d[next] = 1;
        }
        if (!c[i] && a[i] != b[i]) {
          ans *= 2;
          ans %= MOD;
        }
      }
    }

    cout << ans << endl;
  }

 private:
};

// --------------------------------------------
// By default SINGLECASE
int main() {
  FASTIO;

  Solution solution;
  MULTICASE;

  return 0;
}