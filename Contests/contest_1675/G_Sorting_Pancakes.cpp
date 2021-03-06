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
    vi nums(n);
    fori(i, 0, n) cin >> nums[i];

    grid(dp, n + 1, m + 1);
    vector<vector<vector<int>>> dp(n + 1, vvi(m + 1, vi(m + 1)));

    fori(i, 1, n + 1) {
      fori(j, 1, m + 1) {
        fori(k, 1, j + 1) { dp[i][j][k] = dp[i - 1][] }
      }
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