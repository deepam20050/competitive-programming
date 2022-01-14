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

using lli = long long;
using pii = pair < int, int >;

const int N = 1005;

int ans[N][N];
int n, k, d;
vector < int > vals;

void modify () {
  int len = sz(vals) - 1;
  while (len >= 0) {
    vals[len] = (vals[len] + 1) % k;
    if (vals[len]) return;
    --len;
  }
}

int main () {
  scanf("%d %d %d", &n, &k, &d);
  lli curr = 1;
  for (int i = 0; i < d && curr < n; ++i) curr *= k;
  if (curr < n) {
    puts("-1");
    return 0;
  }
  vals.resize(d);
  FOR(i, 0, n) {
    FOR(j, 0, d) {
      ans[j][i] = vals[j]; 
    }
    modify();
  }
  FOR(i, 0, d) FOR(j, 0, n) printf("%d%c", ans[i][j] + 1, " \n"[j == n - 1]);
  return 0;
}
