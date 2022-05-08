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
const int N = 100005;

// --------------------------------------------
// Write your program here
class Solution {
 public:
  void solve() {
    int n;
    cin >> n;
    string s;
    cin >> s;
    int k;
    cin >> k;
    set<char> spe;
    fori(i, 0, k) {
      char c;
      cin >> c;
      spe.insert(c);
    }

    int ans = 0;
    int last = 0;
    fori(i, 1, n) {
      if (spe.count(s[i])) {
        ans = max(ans, i - last);
        last = i;
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