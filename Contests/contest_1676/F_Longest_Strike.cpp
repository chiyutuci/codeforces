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
    int a[n];
    map<int, int> mp;
    for (int i = 0; i < n; i++) {
      cin >> a[i];
      mp[a[i]]++;
    }
    vector<int> c;
    for (auto x : mp) {
      if (x.second >= k) {
        c.push_back(x.first);
      }
    }
    if (c.size() == 0) {
      cout << -1 << endl;
      return;
    }
    sort(c.begin(), c.end());
    int mx = 0;
    int lans = c[0], rans = c[0];
    int l = c[0];
    for (int i = 1; i < c.size(); i++) {
      if (c[i] - 1 == c[i - 1]) {
        if (c[i] - l > mx) {
          lans = l;
          rans = c[i];
          mx = c[i] - l;
        }
      } else {
        l = c[i];
      }
    }
    cout << lans << " " << rans << endl;
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