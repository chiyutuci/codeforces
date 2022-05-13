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
  template <typename T>
  struct binary_indexed_tree {
    int N;
    vector<T> BIT;

    binary_indexed_tree(int N) : N(N), BIT(N + 1, 0) {}

    void add(int i, T x) {
      i++;
      while (i <= N) {
        BIT[i] += x;
        i += i & -i;
      }
    }

    T sum(int i) {
      T ans = 0;
      while (i > 0) {
        ans += BIT[i];
        i -= i & -i;
      }
      return ans;
    }

    T sum(int L, int R) { return sum(R) - sum(L); }
  };

 public:
  void solve() {
    int n;
    cin >> n;
    vi a(n);
    for (int j = 0; j < n; j++) {
      cin >> a[j];
      a[j]--;
    }

    binary_indexed_tree<int> BIT(n);
    ll ans = 0;
    for (int j = 0; j < n; j++) {
      ans += BIT.sum(a[j], n);
      BIT.add(a[j], 1);
    }
    cout << ans << endl;
  }
};

// --------------------------------------------
// By default SINGLECASE
int main() {
  FASTIO;

  Solution solution;
  MULTICASE;

  return 0;
}