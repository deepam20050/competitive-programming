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
int n, m;
vector < vector < int > > p;
bitset < N > present;

bool f (int k) {
  present.reset();
  bool pair = false;
  FOR(i, 0, m) {
    int c = 0;
    FOR(j, 0, n) {
      if (p[i][j] >= k) {
        present[j] = 1;
        ++c;
      }
    }
    pair |= c > 1;
  }
  if (!pair && m > 1) return 0;
  return (int)present.count() == n;
}

void solve () {
  scanf("%d %d", &m, &n);
  p.assign(m, vector < int > (n));
  FOR(i, 0, m) FOR(j, 0, n) { 
    scanf("%d", &p[i][j]);
  }
  int l = 1, r = 1e9 + 5000;
  FOR(i, 0, 30) {
    int mid = l + r >> 1;
    if (f(mid)) {
      l = mid;
    } else {
      r = mid;
    }
  }
  printf("%d\n", l);
}

int main () {
  int tc;
  scanf("%d", &tc);
  while (tc--) {
    solve();
  }
  return 0;
}
