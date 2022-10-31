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

const int N = 1005;

int arr[N][N];
vector < int > row[N], col[N];

int main () {
  int n, m; scanf("%d %d", &n, &m);
  FOR(i, 0, n) FOR(j, 0, m) scanf("%d", arr[i] + j);
  FOR(i, 0, n) {
    row[i].resize(m);
    FOR(j, 0, m) {
      row[i][j] = arr[i][j];
    }
    sort(all(row[i]));
    row[i].erase(unique(all(row[i])), row[i].end());
  }
  FOR(j, 0, m) {
    col[j].resize(n);
    FOR(i, 0, n) {
      col[j][i] = arr[i][j];
    }
    sort(all(col[j]));
    col[j].erase(unique(all(col[j])), col[j].end());
  }
  FOR(i, 0, n) FOR(j, 0, m) {
    int ans = max(sz(row[i]), sz(col[j]));
    int d1 = lb(all(row[i]), arr[i][j]) - row[i].begin();
    int d2 = lb(all(col[j]), arr[i][j]) - col[j].begin();
    if (d1 >= d2) {
      ans = max({ans, d1 + sz(col[j]) - d2});
    } else {
      ans = max({ans, d2 + sz(row[i]) - d1});
    }
    printf("%d%c", ans, " \n"[j == m - 1]);
  }
  return 0;
}