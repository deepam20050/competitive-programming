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

const int N = 1e5 + 5;

int prefx[N], prefy[N];
lli x1, yy1, x2, y2;
int n;
string s;

inline lli abso (lli x) {
  return x < 0 ? -x : x;
}

bool f (lli len) {
  lli mul = len / n;
  lli mod = len % n;
  lli totx = x1 + prefx[n] * mul + prefx[mod];
  lli toty = yy1 + prefy[n] * mul + prefy[mod];
  return abso(x2 - totx) + abso(y2 - toty) <= len;
}

int main () {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cin >> x1 >> yy1 >> x2 >> y2;
  cin >> n;
  cin >> s;
  FOR(i, 1, n + 1) {
    prefx[i] += prefx[i - 1];
    prefy[i] += prefy[i - 1];
    if (s[i - 1] == 'U' || s[i - 1] == 'D') {
      prefy[i] += s[i - 1] == 'U' ? 1 : -1;
    } else {
      prefx[i] += s[i - 1] == 'L' ? -1 : 1;
    }
  }
  lli l = 0, r = 1e18;
  bool ok = 0;
  FOR(i, 0, 60) {
    lli midx = l + r >> 1ll;
    if (f(midx)) {
      r = midx;
      ok = 1;
    } else {
      l = midx;
    }
  }
  if (!ok) r = -1;
  printf("%lld\n", r);
  return 0;
}
