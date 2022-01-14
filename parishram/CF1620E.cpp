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

const int N = 5e5 + 5;

int op[N], x[N], y[N];
int p[N];
int nq;

int main () {
  int nq;
  scanf("%d", &nq);
  FOR(i, 0, nq) {
    scanf("%d %d", op + i, x + i);
    if (op[i] == 2) scanf("%d", y + i);
  }
  iota(p, p + N, 0);
  vector < int > ans;
  for (int i = nq - 1; i >= 0; --i) {
    if (op[i] == 1) {
      ans.eb(p[x[i]]);
    } else {
      p[x[i]] = p[y[i]];
    }
  }
  reverse(all(ans));
  for (auto &e : ans) printf("%d ", e);
  return 0;
}
