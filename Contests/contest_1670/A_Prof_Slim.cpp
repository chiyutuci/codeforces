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
    vi nums(n);
    int mm = 0;
    fori(i, 0, n) {
      cin >> nums[i];
      if (nums[i] < 0) mm++;
    }
    if (nums.size() == 1) {
      cout << "YES" << endl;
      return;
    }

    fori(i, 0, mm) nums[i] = -1 * abs(nums[i]);
    fori(i, mm, nums.size()) nums[i] = abs(nums[i]);

    fori(i, 0, nums.size() - 1) {
      if (nums[i] > nums[i + 1]) {
        cout << "NO" << endl;
        return;
      }
    }

    cout << "YES" << endl;
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