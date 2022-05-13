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
    vector<int> child[n + 7];
    for (int i = 2; i <= n; i++) {
      int x;
      cin >> x;
      child[x].push_back(i);
    }
    string s;
    cin >> s;
    int res = 0;

    function<int(int)> dp = [&](int x) {
      int bal = (s[x - 1] == 'B') ? -1 : 1;
      if (child[x].empty()) {
        return bal;
      }
      for (int i : child[x]) {
        bal += dp(i);
      }
      if (bal == 0) {
        res++;
      }
      return bal;
    };
    dp(1);

    cout << res << '\n';
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