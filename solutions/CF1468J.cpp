// AC
#include "bits/stdc++.h"
using namespace std;

#define sz(x) int((x).size())
#define all(x) begin(x), end(x)
#define pb push_back
#define eb emplace_back
#define mp make_pair
#define F first
#define S second
#define FOR(i, a, b) for (int i = (a); i < (b); ++i)

using lli = long long;
using pii = pair < int, int >;
using t3 = tuple < int, int, int >; 

const int N = 2e5 + 5;

struct DSU {
  int rank[N];
  int p[N];
  void init (int n) {
    for (int i = 1; i <= n; ++i) {
      rank[i] = 0;
      p[i] = i;
    }
  }
  int get (int a) {
    return (p[a] == a) ? a : p[a] = get(p[a]);
  }
  void join (int a, int b) {
    a = get(a);
    b = get(b);
    if (rank[a] == rank[b]) {
      ++rank[a];
    }
    if (rank[a] < rank[b]) {
      swap(a, b);
    }
    p[b] = a;
  }
};

DSU dsu1;
int n, m, k;
vector < t3 > lessk, bigk;

void clean () {
  lessk.clear();
  bigk.clear();
}

void solve () {
  clean();
  scanf("%d %d %d", &n, &m, &k);
  dsu1.init(n);
  int e = 0;
  FOR(i, 0, m) {
    int x, y, s;
    scanf("%d %d %d", &x, &y, &s);
    if (s < k) {
      lessk.eb(s, x, y);
      if (dsu1.get(x) != dsu1.get(y)) {
        ++e;
        dsu1.join(x, y);
      }
    } else {
      bigk.eb(s - k, x, y);
    }
  }
  sort(all(bigk));
  sort(all(lessk));
  lli ans = 0;
  if (e == n - 1) {
    ans = 2e9;
    if (!lessk.empty()) ans = min(ans, 1ll * k - 1ll * get<0>(lessk.back()));
    if (!bigk.empty()) ans = min(ans, 1ll * get<0>(bigk.front()));
  } else {
    for (auto [s, x, y] : bigk) {
      if (e == n - 1) break;
      if (dsu1.get(x) != dsu1.get(y)) {
        ++e;
        ans += s;
        dsu1.join(x, y);
      }
    }
  }
  printf("%lld\n", ans);
}

int main () {
  int tc;
  scanf("%d", &tc);
  while (tc--) {
    solve();
  }
  return 0;
}
