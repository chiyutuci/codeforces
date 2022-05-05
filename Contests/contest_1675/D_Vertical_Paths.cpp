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

    vi par(n + 1);
    vi leaf(n + 1, 1);
    fori(i, 1, n + 1) {
      cin >> par[i];
      if (par[i] != i) leaf[par[i]] = 0;
    }

    vi visit(n + 1);
    cout << count(all(leaf), 1) - 1 << endl;

    fori(i, 1, n + 1) {
      if (leaf[i]) {
        vi path;
        for (int j = i; !visit[j]; j = par[j]) {
          visit[j] = 1;
          path.push_back(j);
        }
        reverse(all(path));
        cout << path.size() << endl;
        for (int x : path) cout << x << " ";
        cout << endl;
      }
    }
    cout << endl;
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