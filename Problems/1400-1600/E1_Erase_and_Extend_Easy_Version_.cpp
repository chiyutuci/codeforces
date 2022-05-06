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
    int n, k;
    cin >> n >> k;
    string s;
    cin >> s;

    string pre;
    pre += s[0];

    string mn = get(pre, k);

    fori(i, 1, s.size()) {
      pre += s[i];
      mn = min(mn, get(pre, k));
    }

    cout << mn << endl;
  }

 private:
  string get(const string& x, int k) {
    string s = x;
    while (s.size() < k) {
      s += s;
    }
    while (s.size() > k) {
      s.pop_back();
    }
    return s;
  }
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