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

const int M = 3e6 + 5;
const int N = 2e5 + 5;

pair < lli, lli > p[N];
int n;
vector < lli > v;
lli pref[M];
lli ans[N];

int main () {
  scanf("%d", &n);
  v.reserve(5 * n + 1);
  v.eb(-1);
  FOR(i, 0, n) {
    lli l, r;
    scanf("%lld %lld", &l, &r);
    v.eb(l - 1);
    v.eb(l);
    v.eb(l + 1);
    v.eb(r - 1);
    v.eb(r);
    v.eb(r + 1);
    p[i] = {l, r};
  }
  sort(all(v));
  v.erase(unique(all(v)), v.end());
  FOR(i, 0, n) {
    int l = lower_bound(all(v), p[i].F) - v.begin();
    int r = lower_bound(all(v), p[i].S + 1) - v.begin();
    ++pref[l];
    --pref[r];
  }
  FOR(i, 1, M) {
    pref[i] += pref[i - 1];
  }
  for (int i = 0; i < sz(v); ++i) {
    int c = pref[i];
    if (c == 0) {
      continue;
    }
    int j = i;
    while (j < sz(v) && pref[j] == c) {
      ++j;
    }
    lli cnt = v[j - 1] - v[i] + 1;
    ans[c] += cnt;
    i = j - 1;
  }
  FOR(i, 1, n + 1) {
    printf("%lld ", ans[i]);
  }
  return 0;
}
