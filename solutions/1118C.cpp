#include "bits/stdc++.h"
using namespace std;

#define sz(x) int((x).size())
#define all(x) begin(x), end(x)
#define eb emplace_back
#define em emplace
#define mp make_pair
#define F first
#define S second
#define FOR(i, a, b) for (int i = (a); i < (b); ++i)
#define lb lower_bound
#define ub upper_bound

using lli = long long;
using pii = pair < int, int >;

const int N = 1001;
const int M = 21;

int ans[M][M];
int cnt[N];
vector < tuple < int, int, int > > v;

int main () {
  ios_base::sync_with_stdio(0); cin.tie(0);
  int n; cin >> n;
  FOR(i, 0, n * n) {
    int x; cin >> x;
    ++cnt[x];
  }
  FOR(i, 0, n + 1 >> 1) FOR(j, 0, n + 1 >> 1) {
    if (i != n - 1 - i && j != n - 1 - j) {
      v.eb(4, i, j);
    } else if ((i != n - 1 - i) ^ (j != n - 1 - j)) {
      v.eb(2, i, j);
    } else {
      v.eb(1, i, j);
    }
  }
  for (auto req : {4, 2, 1}) {
    int lst = 1;
    for (auto [siz, x, y] : v) {
      if (siz != req) continue;
      while (lst < N && cnt[lst] < req) {
        ++lst;
      }
      if (lst == N) {
        cout << "NO\n";
        exit(0);
      }
      ans[x][y] = ans[x][n - 1 - y] = ans[n - 1 - x][y] = ans[n - 1 - x][n - 1 - y] = lst;
      cnt[lst] -= req;
    }
  }
  cout << "YES\n";
  FOR(i, 0, n) FOR(j, 0, n) {
    cout << ans[i][j] << " \n"[j == n - 1];
  }
  return 0;
}