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

const int N = 3e5 + 5;
const int LN = 19;

int a[N];
int n;

struct Data {
  int min, gcd;
  Data () {
    min = 1e9;
    gcd = 0;
  }
};
Data st[LN][N];

void build () {
  FOR(i, 1, n + 1) {
    st[0][i].gcd = a[i];
    st[0][i].min = a[i];
  }
  FOR(i, 1, LN) {
    for (int j = 1; j + (1 << i) - 1 <= n; ++j) {
      st[i][j].gcd = __gcd(st[i - 1][j].gcd, st[i - 1][j + (1 << (i - 1))].gcd);
      st[i][j].min = min(st[i - 1][j].min, st[i - 1][j + (1 << (i - 1))].min);
    }
  }
}

Data query (int l, int r) {
  int t = __lg(r - l + 1);
  Data ret;
  ret.gcd = __gcd(st[t][l].gcd, st[t][r - (1 << t) + 1].gcd);
  ret.min = min(st[t][l].min, st[t][r - (1 << t) + 1].min);
  return ret;
}

inline bool f (int len) {
  for (int i = 1; i + len <= n; ++i) {
    auto ret = query(i, i + len);
    if (ret.gcd == ret.min) {
      return 1;
    }
  }
  return 0;
}

int main () {
  scanf("%d", &n);
  FOR(i, 1, n + 1) {
    scanf("%d", a + i);
  }
  build();
  int l = 0, r = n;
  FOR(i, 0, 50) {
    int mid = l + r >> 1;
    if (f(mid)) {
      l = mid;
    } else {
      r = mid;
    }
  }
  vector < int > ans;
  for (int i = 1; i + l <= n; ++i) {
    auto ret = query(i, i + l);
    if (ret.gcd == ret.min) {
      ans.eb(i);
    }
  }
  printf("%d %d\n", sz(ans), l);
  for (auto &x : ans) {
    printf("%d ", x);
  }
  return 0;
}
