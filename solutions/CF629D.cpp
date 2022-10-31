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

const double PI = acos(-1.0);
const int N = 1e5 + 5;

lli bit[N];
pair < lli, int > v[N];
int n;

lli get_vol (int r, int h) {
  return r * 1ll * r * h; 
}

void update (int idx, lli add) {
  while (idx < N) {
    bit[idx] = max(bit[idx], add);
    idx += idx & -idx;
  }
}

lli query (int idx) {
  lli ret = 0;
  while (idx > 0) {
    ret = max(ret, bit[idx]);
    idx -= idx & -idx;
  }
  return ret;
}

int main () {
  scanf("%d", &n);
  FOR(i, 1, n + 1) {
    int r, h;
    scanf("%d %d", &r, &h);
    v[i - 1] = {get_vol(r, h), -i};
  }
  sort(v, v + n);
  lli ans = 0;
  FOR(i, 0, n) {
    auto [vol, idx] = v[i];
    idx *= -1;
    auto best = query(idx - 1) + vol;
    update(idx, best);
    ans = max(ans, best);
  }
  printf("%.9lf\n", PI * ans);
  return 0;
}
