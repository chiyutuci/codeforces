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
    string s;
    cin >> s;

    int l = 0;
    char c = s[l];
    int cnt = 1;
    int ans = 0;
    int seg = 1;
    fori(i, 0, n - 1) {
      if (s[i + 1] != c) {
        if (cnt & 1) {
          int cn = 0;
          for (int j = i + 1; j < n; j++) {
            if (s[j] == c) break;
            cn++;
          }
          if (cn < 3) {
            s[i + 1] = c;
            cnt++;
            ans++;
            continue;
          }
          s[i] = s[i + 1];
          c = s[i + 1];
          ans++;
          seg++;
          cnt = 2;
          continue;
        } else {
          if (i < n - 2 && s[i + 2] == c) {
            s[i + 1] = c;
            ans++;
            cnt++;
          } else {
            c = s[i + 1];
            cnt = 1;
            seg++;
          }
        }
      } else
        cnt++;
    }

    cout << ans << " " << seg << endl;
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