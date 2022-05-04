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
const int N = 1000001;
class Solution {
 public:
  void solve() {
    int a, b;
    cin >> a >> b;

    int ans = b - a;
    fori(a1, a, b) {
      int b1 = 0;
      for (int i = 21; i >= 0; i--) {
        if ((b >> i) & 1)
          b1 ^= (1 << i);
        else {
          if ((a1 >> i) & 1) {
            b1 ^= (1 << i);
            break;
          }
        }
      }
      ans = min(ans, a1 - a + 1 + (a1 | b1) - b);
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
  // SINGLECASE;
  MULTICASE;

  return 0;
}