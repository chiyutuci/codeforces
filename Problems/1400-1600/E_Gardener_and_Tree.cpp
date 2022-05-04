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
#define SINGLECASE solution.solve();
#define MULTICASE                                                              \
  int t;                                                                       \
  cin >> t;                                                                    \
  while (t--)                                                                  \
    solution.solve();
#define FASTIO                                                                 \
  ios::sync_with_stdio(false);                                                 \
  cin.tie(nullptr);
#define fori(i, l, r) for (int i = l; i < r; i++)
#define read(a)                                                                \
  for (int &x : a)                                                             \
    cin >> x;
#define grid(x, m, n) vvi x(m, vi(n));
#define gridl(x, m, n) vvl x(m, vl(n));
#define all(x) x.begin(), x.end()

// --------------------------------------------
// Write your program here
const int N = 100005;
class Solution {
public:
  void solve() {
    int n, k;
    cin >> n >> k;

    vvi tree(n + 1);
    vi adj(n + 1);
    vi need(n + 1);
    fori(i, 1, n) {
      int x, y;
      cin >> x >> y;
      tree[x].push_back(y);
      tree[y].push_back(x);
      adj[x]++;
      adj[y]++;
    }

    queue<int> q;
    // O(n)
    fori(i, 1, n + 1) {
      if (adj[i] == 1) {
        q.push(i);
        need[i] = 1;
      }
    }

    // O(2E + V)
    while (!q.empty()) {
      int dd = q.front();
      q.pop();
      // O(E(v)) for every v;
      for (int x : tree[dd]) {
        if (adj[x] > 1) {
          adj[x]--;
          if (adj[x] == 1) {
            q.push(x);
            need[x] = need[dd] + 1;
          }
        }
      }
    }

    int ans = 0;
    fori(i, 1, n + 1) {
      if (need[i] > k)
        ans++;
    }

    cout << ans << endl;
  }

private:
};

// --------------------------------------------
// By default SINGLECASE
signed main() {
  FASTIO;

  Solution solution;
  // SINGLECASE;
  MULTICASE;

  return 0;
}