#include "bits/stdc++.h"
using namespace std;

#define sz(x) int((x).size())
#define all(x) begin(x), end(x)
#define eb emplace_back
#define em emplace
#define F first
#define S second
#define FOR(i, a, b) for (int i = (a); i < (b); ++i)
#define lb lower_bound
#define ub upper_bound

using lli = long long;
using pii = pair < int, int >;

map < lli, lli > mp;

void update (lli a, lli b, lli x) {
  while (a != b) {
    if (a > b) {
      mp[a] += x;
      a >>= 1ll;
    } else {
      mp[b] += x;
      b >>= 1ll;
    }
  }
}

lli query (lli a, lli b) {
  lli ans = 0;
  while (a != b) {
    if (a > b) {
      ans += mp[a];
      a >>= 1ll;
    } else {
      ans += mp[b];
      b >>= 1ll;
    }
  }
  return ans;
}

int main () {
  int nq; scanf("%d", &nq);
  while (nq--) {
    int op; scanf("%d", &op);
    if (op == 1) {
      lli u, v, w; scanf("%lld %lld %lld", &u, &v, &w);
      update(u, v, w);
    } else {
      lli u, v; scanf("%lld %lld", &u, &v);
      printf("%lld\n", query(u, v));
    }
  }
  return 0;
}
