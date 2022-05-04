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
#define MULTICASE \
  int t;          \
  cin >> t;       \
  while (t--) solution.solve();
#define FASTIO                 \
  ios::sync_with_stdio(false); \
  cin.tie(nullptr);
#define fori(i, l, r) for (int i = l; i < r; i++)
#define read(a) \
  for (int &x : a) cin >> x;
#define grid(x, m, n) vvi x(m, vi(n));
#define gridl(x, m, n) vvl x(m, vl(n));
#define all(x) x.begin(), x.end()

// --------------------------------------------
// Write your program here
const int N = 1001;
vi v(N, N);

class Solution {
 public:
  void solve() {
    int n, k;
    cin >> n >> k;
    vi b(n), c(n);
    read(b);
    read(c);

    int sum = 0;
    for (int x : b) sum += v[x];
    k = min(k, sum);

    vi dp(k + 1);
    fori(i, 0, n) {
      for (int j = k - v[b[i]]; j >= 0; j--) {
        dp[j + v[b[i]]] = max(dp[j + v[b[i]]], dp[j] + c[i]);
      }
    }

    cout << dp[k] << endl;
  }

 private:
};

// --------------------------------------------
// By default SINGLECASE
signed main() {
  FASTIO;

  v[1] = 0;
  fori(i, 1, N) {
    fori(x, 1, i + 1) {
      int j = i + i / x;
      if (j < N) v[j] = min(v[j], v[i] + 1);
    }
  }

  Solution solution;
  // SINGLECASE;
  MULTICASE;

  return 0;
}