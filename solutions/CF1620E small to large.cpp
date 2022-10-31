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

vector < int > p[N];

int main () {
  int nq;
  scanf("%d", &nq);
  int n = 0;
  FOR(i, 0, nq) {
    int op;
    scanf("%d", &op);
    if (op == 1) {
      int x;
      scanf("%d", &x);
      p[x].eb(n++);
    } else {
      int x, y;
      scanf("%d %d", &x, &y);
      if (x == y) continue;
      if (sz(p[x]) >= sz(p[y])) p[x].swap(p[y]);
      for (auto &e : p[x]) p[y].eb(e);
      p[x].clear();
    }
  }
  vector < int > ans(n);
  FOR(i, 1, N) {
    for (auto &e : p[i]) {
      ans[e] = i;
    }
  }
  FOR(i, 0, n) printf("%d ", ans[i]);
  return 0;
}
